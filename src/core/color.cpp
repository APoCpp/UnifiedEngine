#include <unified/core/color.hpp>
#include <GLFW/glfw3.h>

UNIFIED_BEGIN_NAMESPACE

Color::Color() _OSL_NOEXCEPT : r(0), g(0), b(0), a(0) { }

Color::Color(u8 r, u8 g, u8 b) _OSL_NOEXCEPT : r(r), g(g), b(b), a(255) { }

Color::Color(u8 r, u8 g, u8 b, u8 a) _OSL_NOEXCEPT : r(r), g(g), b(b), a(a) { }

UNIFIED_END_NAMESPACE
