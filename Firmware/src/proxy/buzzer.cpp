#include "proxy/buzzer.hpp"

using namespace proxy;

Buzzer::Buzzer(uint8_t buzzer_pin) : buzzer_pin(buzzer_pin)
{
    pinMode(buzzer_pin, OUTPUT);
}

void Buzzer::start_tone(uint16_t frequency)
{
    tone(buzzer_pin, frequency);
}

void Buzzer::play_tone(unsigned int frequency, unsigned long duration)
{
    tone(buzzer_pin, frequency, duration);
    delay(duration);
    noTone(buzzer_pin);
}

void Buzzer::stop_tone()
{
    noTone(buzzer_pin);
}
