#ifndef UNIFIED_CORE_COLOR_HPP
#define UNIFIED_CORE_COLOR_HPP

#include <unified/defines.hpp>

UNIFIED_BEGIN_NAMESPACE

class Color
{
public:

    Color() _UNIFIED_NOEXCEPT :
        r(0.f), g(0.f), b(0.f), a(1.f) { }

    Color(float r, float g, float b) _UNIFIED_NOEXCEPT :
        r(r), g(g), b(b), a(1.f) { }

    Color(float r, float g, float b, float a) _UNIFIED_NOEXCEPT :
        r(r), g(g), b(b), a(a) { }

    float r, g, b, a;

};

UNIFIED_END_NAMESPACE

#endif
