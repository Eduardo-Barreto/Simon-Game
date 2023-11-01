#ifndef __LED_HPP__
#define __LED_HPP__

#include "hal/gpio.hpp"
namespace proxy
{
    class Led
    {
    public:
        struct Config
        {
            hal::Gpio::Config gpio_config;
        };

        Led(const Config &config);

        void write(bool value);

        void on();

        void off();

        void toggle();

        void blink(uint32_t period);

    private:
        hal::Gpio gpio;
        uint64_t last_blink;
    };
};

#endif // __LED_HPP__