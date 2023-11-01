#ifndef __CFG_TARGET_HPP__
#define __CFG_TARGET_HPP__

#include <Arduino.h>
#include <vector>

#include "proxy/button.hpp"
#include "proxy/led.hpp"
#include "proxy/buzzer.hpp"
#include "utils/logger.hpp"

/*****************************************
 * PROXY CONFIGURATION
 *****************************************/

constexpr proxy::Button::Config red_button_config = {
    .gpio_config = {
        .pin = 32,
        .mode = INPUT_PULLUP,
    },
};

constexpr proxy::Button::Config green_button_config = {
    .gpio_config = {
        .pin = 33,
        .mode = INPUT_PULLUP,
    },
};

constexpr proxy::Button::Config blue_button_config = {
    .gpio_config = {
        .pin = 25,
        .mode = INPUT_PULLUP,
    },
};

constexpr proxy::Button::Config yellow_button_config = {
    .gpio_config = {
        .pin = 26,
        .mode = INPUT_PULLUP,
    },
};

constexpr proxy::Button::Config reset_button_config = {
    .gpio_config = {
        .pin = 27,
        .mode = INPUT_PULLUP,
    },
};

constexpr proxy::Led::Config red_led_config = {
    .gpio_config = {
        .pin = 23,
        .mode = OUTPUT,
    },
};

constexpr proxy::Led::Config green_led_config = {
    .gpio_config = {
        .pin = 22,
        .mode = OUTPUT,
    },
};

constexpr proxy::Led::Config blue_led_config = {
    .gpio_config = {
        .pin = 21,
        .mode = OUTPUT,
    },
};

constexpr proxy::Led::Config yellow_led_config = {
    .gpio_config = {
        .pin = 19,
        .mode = OUTPUT,
    },
};

constexpr uint8_t buzzer_pin = 18;

/*****************************************
 * PROXY INSTANCES
 *****************************************/

extern std::vector<uint16_t> tones;

extern proxy::Button reset_button;
extern proxy::Buzzer buzzer;
extern std::vector<proxy::Button> buttons;
extern std::vector<proxy::Led> leds;
extern utils::Logger logger;

#endif // __CFG_TARGET_HPP__