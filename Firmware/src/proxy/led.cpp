#include "proxy/led.hpp"

using namespace proxy;

Led::Led(const Config &config) : gpio(config.gpio_config)
{
}

void Led::write(bool value)
{
    gpio.write(value);
}

void Led::on()
{
    gpio.write(1);
}

void Led::off()
{
    gpio.write(0);
}

void Led::toggle()
{
    gpio.toggle();
}

void Led::blink(uint32_t period)
{
    if (millis() < last_blink + period)
        return;

    this->toggle();
    period = millis();
}