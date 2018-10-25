#include "vex_types.h"

vex::color::color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) : underlying(sf::Color(r, g, b, a)) { }

const vex::color vex::color::black(0, 0, 0);
const vex::color vex::color::white(255, 255, 255);
const vex::color vex::color::red(255, 0, 0);
const vex::color vex::color::green(0, 255, 0);
const vex::color vex::color::blue(0, 0, 255);
const vex::color vex::color::yellow(255, 255, 0);
const vex::color vex::color::orange(255, 165, 0);
const vex::color vex::color::purple(255, 0, 255);
const vex::color vex::color::cyan(0, 255, 255);
const vex::color vex::color::transparent(0, 0, 0, 0);