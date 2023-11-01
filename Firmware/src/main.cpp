#include "cfg/target.hpp"
#include "controllers/simon.hpp"

std::vector<uint16_t> tones = {
    262, // C
    330, // E
    392, // G
    494, // B
};

proxy::Button reset_button(reset_button_config);

std::vector<proxy::Button> buttons = {
    proxy::Button(red_button_config),
    proxy::Button(green_button_config),
    proxy::Button(blue_button_config),
    proxy::Button(yellow_button_config),
};

std::vector<proxy::Led> leds = {
    proxy::Led(red_led_config),
    proxy::Led(green_led_config),
    proxy::Led(blue_led_config),
    proxy::Led(yellow_led_config),
};

proxy::Buzzer buzzer(buzzer_pin);

utils::Logger logger(LOG_LEVEL_DEBUG, "main");
controller::Simon simon(leds, buttons, reset_button, buzzer, tones);

void setup()
{
    simon.reset();
}

void loop()
{
    simon.loop();
}