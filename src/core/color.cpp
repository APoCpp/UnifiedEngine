#include <unified/core/color.hpp>
#include <GLFW/glfw3.h>

UNIFIED_BEGIN_NAMESPACE

Color::Color() : r(0), g(0), b(0), a(0) { }

Color::Color(u8 r, u8 g, u8 b, u8 a) : r(r), g(g), b(b), a(a) { }

UNIFIED_END_NAMESPACE
