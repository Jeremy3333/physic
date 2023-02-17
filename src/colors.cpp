#include "Colors.hpp"

Colors::Colors(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {}

Colors::Colors(int r, int g, int b) : r(r), g(g), b(b), a(255) {}

Colors::Colors() : r(0), g(0), b(0), a(255) {}

Colors::~Colors() {}