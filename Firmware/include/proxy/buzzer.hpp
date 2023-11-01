#ifndef BUZZER_HPP
#define BUZZER_HPP

#include <Arduino.h>

namespace proxy
{
    class Buzzer
    {
    public:
        Buzzer(uint8_t buzzer_pin);

        void start_tone(uint16_t frequency);
        void play_tone(unsigned int frequency, unsigned long duration);
        void stop_tone();

    private:
        uint8_t buzzer_pin;
    };
};

#endif // BUZZER_HPP
