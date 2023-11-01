#include "hal/gpio.hpp"

using namespace hal;

Gpio::Gpio(const Config& gpio_config) :
    pin(gpio_config.pin), pullup_resistor(gpio_config.mode == INPUT_PULLUP) {
    pinMode(this->pin, gpio_config.mode);
}

bool Gpio::read(void) const {
    return digitalRead(this->pin) != this->pullup_resistor;
}

void Gpio::write(bool state) {
    digitalWrite(this->pin, state);
}

void Gpio::on(void) {
    this->write(true);
}

void Gpio::off(void) {
    this->write(false);
}

void Gpio::toggle(void) {
    this->write(!this->read());
}
