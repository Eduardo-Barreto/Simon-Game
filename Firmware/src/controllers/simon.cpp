#include "controllers/simon.hpp"

using namespace controller;

Simon::Simon(
    std::vector<proxy::Led> &leds,
    std::vector<proxy::Button> &buttons,
    proxy::Button &reset_button,
    proxy::Buzzer &buzzer,
    std::vector<uint16_t> &tones) : leds(leds), buttons(buttons), reset_button(reset_button), buzzer(buzzer), tones(tones)
{
}

void Simon::control_leds(bool state)
{
    for (uint8_t i = 0; i < leds.size(); i++)
    {
        leds[i].write(state);
    }
    buzzer.stop_tone();
}

void Simon::blink_once(uint8_t led_index, uint16_t blink_time)
{
    buzzer.start_tone(tones[led_index]);
    leds[led_index].on();
    delay(blink_time);
    leds[led_index].off();
    buzzer.stop_tone();
    delay(blink_time / 3);
}

void Simon::lose_song()
{
    for (uint8_t i = tones.size(); i > 0; i--)
    {
        buzzer.start_tone(tones[i - 1]);
        delay(150);
        buzzer.stop_tone();
        delay(150);
    }
}

uint8_t Simon::get_pressed_button()
{
    uint8_t pressed_button = 255;
    uint32_t start_time = millis();
    while (pressed_button == 255)
    {
        if (millis() - start_time > 5000)
        {
            return 255;
        }
        for (uint8_t i = 0; i < buttons.size(); i++)
        {
            buttons[i].read();
            if (buttons[i].rising_edge())
            {
                return i;
            }
        }
    }

    return 255;
}

void Simon::reset()
{
    sequence.clear();
    state = WAITING_FOR_START;
}

void Simon::loop()
{
    logger.debug("State: " + (String)state);
    switch (state)
    {
    case WAITING_FOR_START:
    {
        reset();
        while (!reset_button.is_pressed())
            ;

        state = INIT;

        break;
    }
    case INIT:
    {
        control_leds(false);
        state = PLAYING_SEQUENCE;
        break;
    }
    case PLAYING_SEQUENCE:
    {
        control_leds(false);
        delay(1000);

        uint8_t new_number = random(0, leds.size());
        sequence.push_back(new_number);

        for (uint8_t i = 0; i < sequence.size(); i++)
        {
            blink_once(sequence[i]);
        }

        state = READING_INPUT;
        break;
    }
    case READING_INPUT:
    {
        for (uint8_t i = 0; i < sequence.size(); i++)
        {
            uint8_t right_button = sequence[i];
            uint8_t pressed_button = get_pressed_button();

            logger.debug("Expectativa: " + (String)right_button + " Realidade: " + (String)pressed_button);

            if (pressed_button == 255)
            {
                state = LOSE;
                return;
            }

            if (pressed_button != right_button)
            {
                state = LOSE;
                return;
            }

            blink_once(right_button, 250);
        }

        state = PLAYING_SEQUENCE;
        break;
    }
    case LOSE:
    {
        control_leds(true);
        lose_song();
        delay(1000);
        logger.info("Você perdeu.");
        state = WAITING_FOR_START;
        break;
    }
    }
}