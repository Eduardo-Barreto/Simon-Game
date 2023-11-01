#ifndef __PROXY_BUTTON_HPP__
#define __PROXY_BUTTON_HPP__

#include "hal/gpio.hpp"

namespace proxy
{
    class Button
    {
    public:
        struct Config
        {
            hal::Gpio::Config gpio_config;
        };

        /**
         * @brief Construct a new Button object
         *
         * @param button_config
         */
        Button(const Config &button_config);

        bool read();

        bool is_pressed();

        bool is_released();

        bool faling_edge();

        bool rising_edge();

    private:
        hal::Gpio gpio;
        bool current_state;
        bool last_state;
        uint32_t last_read_time;
        uint8_t debounce_time = 10;
    };
}

#endif // __PROXY_BUTTON_HPP__