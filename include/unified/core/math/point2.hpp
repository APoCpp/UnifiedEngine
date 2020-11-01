#ifndef UNIFIED_CORE_MATH_POINT2_HPP
#define UNIFIED_CORE_MATH_POINT2_HPP

#include <unified/core/math/point_fwd.hpp>
#include <fmt/format.h>

UNIFIED_BEGIN_NAMESPACE

template <class _type>
struct Point<_type, 2>
{
    _type x, y;

    _OSL_CONSTEXPR Point() _OSL_NOEXCEPT : x(_type()), y(_type()) { }
    _OSL_CONSTEXPR Point(_type xy) _OSL_NOEXCEPT : x(xy), y(xy) { }
    _OSL_CONSTEXPR Point(_type x, _type y) _OSL_NOEXCEPT : x(x), y(y) { }

    _OSL_CONSTEXPR _type operator[](u32 i) const _OSL_NOEXCEPT {
        _OSL_CONSTEXPR _type Point::*accessors[] = {
            &Point::x,
            &Point::y
        };
        return this->*accessors[i];
    }

    _OSL_CONSTEXPR _type &operator[](u32 i) _OSL_NOEXCEPT {
        _OSL_CONSTEXPR _type Point::*accessors[] = {
            &Point::x,
            &Point::y
        };
        return this->*accessors[i];
    }

    _OSL_CONSTEXPR Point operator+(_type const &r) const _OSL_NOEXCEPT {
        return Point(x + r, y + r);
    }

    _OSL_CONSTEXPR Point operator+(Point const &r) const _OSL_NOEXCEPT {
        return Point(x + r.x, y + r.y);
    }

    _OSL_CONSTEXPR Point operator-(_type const &r) const _OSL_NOEXCEPT {
        return Point(x - r, y - r);
    }

    _OSL_CONSTEXPR Point operator-(Point const &r) const _OSL_NOEXCEPT {
        return Point(x - r.x, y - r.y);
    }

    _OSL_CONSTEXPR Point operator*(_type const &r) const _OSL_NOEXCEPT {
        return Point(x * r, y * r);
    }

    _OSL_CONSTEXPR Point operator*(Point const &r) const _OSL_NOEXCEPT {
        return Point(x * r.x, y * r.y);
    }

    _OSL_CONSTEXPR Point operator/(_type const &r) const _OSL_NOEXCEPT {
        return Point(x / r, y / r);
    }

    _OSL_CONSTEXPR Point operator/(Point const &r) const _OSL_NOEXCEPT {
        return Point(x / r.x, y / r.y);
    }

    _OSL_CONSTEXPR Point &operator+=(_type const &r) _OSL_NOEXCEPT {
        x += r, y += r;
        return *this;
    }

    _OSL_CONSTEXPR Point &operator+=(Point const &r) _OSL_NOEXCEPT {
        x += r.x, y += r.y;
        return *this;
    }

    _OSL_CONSTEXPR Point &operator-=(_type const &r) _OSL_NOEXCEPT {
        x -= r, y -= r;
        return *this;
    }

    _OSL_CONSTEXPR Point &operator-=(Point const &r) _OSL_NOEXCEPT {
        x -= r.x, y -= r.y;
        return *this;
    }

    _OSL_CONSTEXPR Point &operator*=(_type const &r) _OSL_NOEXCEPT {
        x *= r, y *= r;
        return *this;
    }

    _OSL_CONSTEXPR Point &operator*=(Point const &r) _OSL_NOEXCEPT {
        x *= r.x, y *= r.y;
        return *this;
    }

    _OSL_CONSTEXPR Point &operator/=(_type const &r) _OSL_NOEXCEPT {
        x /= r, y /= r;
        return *this;
    }

    _OSL_CONSTEXPR Point &operator/=(Point const &r) _OSL_NOEXCEPT {
        x /= r.x, y /= r.y;
        return *this;
    }

    _OSL_CONSTEXPR u32 size() const _OSL_NOEXCEPT {
        return 2;
    }
};

typedef Point<unsigned, 2> Point2u;
typedef Point<int,      2> Point2i;
typedef Point<float,    2> Point2f;
typedef Point<double,   2> Point2d;

UNIFIED_END_NAMESPACE

template <class _type> struct fmt::formatter<UNIFIED_NAMESPACE::Point<_type, 2>> : fmt::formatter<std::string> {
    template <class FormatContext>
    auto format(const UNIFIED_NAMESPACE::Point<_type, 2> &vector, FormatContext &ctx) {
        return formatter<std::string>::format(fmt::format("{{ {}, {} }}", vector.x, vector.y), ctx);
    }
};

#endif
