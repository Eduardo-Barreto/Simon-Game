#ifndef __GPIO_HPP__
#define __GPIO_HPP__

#include <Arduino.h>

namespace hal {
class Gpio {
    public:
        struct Config {
            uint8_t pin;
            uint8_t mode;
        };

        /**
         * @brief Construct a new GPIO object
         *
         * @param gpio_config Configuration of the gpio instance
         */
        Gpio(const Config& gpio_config);

        /**
         * @brief Read the GPIO pin
         *
         * @return True if the pin is high, false otherwise
         */
        bool read(void) const;

        /**
         * @brief Write to the GPIO pin
         *
         * @param state Desired state of the GPIO pin
         */
        void write(bool state);

        /**
         * @brief Turn the GPIO pin on
         */
        void on(void);

        /**
         * @brief Turn the GPIO pin off
         */
        void off(void);

        /**
         * @brief Toggle the GPIO pin
         */
        void toggle(void);

    private:
        uint8_t pin;
        bool pullup_resistor;
};
};

#endif // __GPIO_HPP__
