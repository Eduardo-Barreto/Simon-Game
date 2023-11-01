#ifndef __SIMON_HPP__
#define __SIMON_HPP__

#include <vector>
#include "cfg/target.hpp"
#include "utils/logger.hpp"

constexpr uint8_t max_sequence = 4;
constexpr uint16_t blink_time = 750;

namespace controller
{
    class Simon
    {
    public:
        Simon(std::vector<proxy::Led> &leds, std::vector<proxy::Button> &buttons, proxy::Button &reset_button, proxy::Buzzer &buzzer, std::vector<uint16_t> &tones);

        void control_leds(bool state);

        void blink_once(uint8_t led_index, uint16_t blink_time = blink_time);

        void lose_song();

        uint8_t get_pressed_button(void);

        void reset(void);

        void loop(void);

    private:
        enum State
        {
            WAITING_FOR_START = 0,
            INIT = 1,
            PLAYING_SEQUENCE = 2,
            READING_INPUT = 3,
            LOSE = 4
        };

        State state = WAITING_FOR_START;

        const std::vector<uint16_t> tones;

        proxy::Button &reset_button;
        proxy::Buzzer &buzzer;
        std::vector<proxy::Led> &leds;
        std::vector<proxy::Button> &buttons;
        std::vector<uint8_t> sequence;

        utils::Logger logger = utils::Logger(LOG_LEVEL_DEBUG, "simon");
    };
};

#endif // __SIMON_HPP__