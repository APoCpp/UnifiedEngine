#ifndef _UNIFIED_GRAPHICS_COLOR_HPP
#define _UNIFIED_GRAPHICS_COLOR_HPP

# include <unified/defines.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

class Color
{
public:

    UNIFIED_CONSTEXPR Color() :
        r(0.f), g(0.f), b(0.f), a(1.f) { }

    UNIFIED_CONSTEXPR Color(float r, float g, float b) :
        r(r), g(g), b(b), a(1.f) { }

    UNIFIED_CONSTEXPR Color(float r, float g, float b, float a) :
        r(r), g(g), b(b), a(a) { }

    template <class _type>
    UNIFIED_CONSTEXPR bool operator==(const _type &r) const {
        return this->r == r && this->g == r && this->b == r && this->a == r;
    }

    UNIFIED_CONSTEXPR bool operator==(const Color &r) const {
        return this->r == r.r && this->g == r.g && this->b == r.b && this->a == r.a;
    }

    template <class _type>
    UNIFIED_CONSTEXPR bool operator!=(const _type &r) const {
        return !this->operator==(r);
    }

    UNIFIED_CONSTEXPR bool operator!=(const Color &r) const {
        return !this->operator==(r);
    }

    float r, g, b, a;

};

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE

#endif
