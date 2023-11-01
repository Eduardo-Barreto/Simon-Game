#include "proxy/button.hpp"

using namespace proxy;

Button::Button(const Config &button_config) : gpio(button_config.gpio_config)
{
}

bool Button::read()
{
    if (millis() - this->last_read_time < debounce_time)
    {
        return this->current_state;
    }

    this->last_state = this->current_state;
    this->current_state = this->gpio.read();

    if (this->current_state != this->last_state)
    {
        this->last_read_time = millis();
    }

    return this->current_state;
}

bool Button::is_pressed()
{
    return this->read();
}

bool Button::is_released()
{
    return !this->read();
}

bool Button::faling_edge()
{
    return this->last_state && !this->current_state;
}

bool Button::rising_edge()
{
    return !this->last_state && this->current_state;
}
