#include <unified/core/math/point_fwd.hpp>

#ifndef UNIFIED_CORE_POINT2_HPP
#define UNIFIED_CORE_POINT2_HPP

namespace Unified
{
    template <class _type>
    struct Point<_type, 2> {
        
        _type x, y;

        Point() : x(_type()), y(_type()) { }
        Point(_type xy) : x(xy), y(xy) { }
        Point(_type x, _type y) : x(x), y(y) { }

        _type operator[](u32 i) const _OSL_NOEXCEPT {
            _OSL_CONSTEXPR _type Point::*accessors[] = {
                &Point::x,
                &Point::y
            }; return this->*accessors[i];
        }

        _type &operator[](u32 i) _OSL_NOEXCEPT {
            _OSL_CONSTEXPR _type Point::*accessors[] = {
                &Point::x,
                &Point::y
            }; return this->*accessors[i];
        }

        _OSL_CONSTEXPR Point operator+(const _type &r) const _OSL_NOEXCEPT {
            return Point(x + r, y + r);
        }

        _OSL_CONSTEXPR Point operator+(const Point &r) const _OSL_NOEXCEPT {
            return Point(x + r.x, y + r.y);
        }

        _OSL_CONSTEXPR Point operator-(const _type &r) const _OSL_NOEXCEPT {
            return Point(x - r, y - r);
        }

        _OSL_CONSTEXPR Point operator-(const Point &r) const _OSL_NOEXCEPT {
            return Point(x - r.x, y - r.y);
        }

        _OSL_CONSTEXPR Point operator*(const _type &r) const _OSL_NOEXCEPT {
            return Point(x * r, y * r);
        }

        _OSL_CONSTEXPR Point operator*(const Point &r) const _OSL_NOEXCEPT {
            return Point(x * r.x, y * r.y);
        }

        _OSL_CONSTEXPR Point operator/(const _type &r) const _OSL_NOEXCEPT {
            return Point(x / r, y / r);
        }

        _OSL_CONSTEXPR Point operator/(const Point &r) const _OSL_NOEXCEPT {
            return Point(x / r.x, y / r.y);
        }

        _OSL_CONSTEXPR Point &operator+=(const _type &r) _OSL_NOEXCEPT {
            x += r, y += r;
            return *this;
        }

        _OSL_CONSTEXPR Point &operator+=(const Point &r) _OSL_NOEXCEPT {
            x += r.x, y += r.y;
            return *this;
        }

        _OSL_CONSTEXPR Point &operator-=(const _type &r) _OSL_NOEXCEPT {
            x -= r, y -= r;
            return *this;
        }

        _OSL_CONSTEXPR Point &operator-=(const Point &r) _OSL_NOEXCEPT {
            x -= r.x, y -= r.y;
            return *this;
        }

        _OSL_CONSTEXPR Point &operator*=(const _type &r) _OSL_NOEXCEPT {
            x *= r, y *= r;
            return *this;
        }

        _OSL_CONSTEXPR Point &operator*=(const Point &r) _OSL_NOEXCEPT {
            x *= r.x, y *= r.y;
            return *this;
        }

        _OSL_CONSTEXPR Point &operator/=(const _type &r) _OSL_NOEXCEPT {
            x /= r, y /= r;
            return *this;
        }

        _OSL_CONSTEXPR Point &operator/=(const Point &r) _OSL_NOEXCEPT {
            x /= r.x, y /= r.y;
            return *this;
        }

        _OSL_CONSTEXPR float length() const _OSL_NOEXCEPT {
            return (x * x + y * y);
        }

        _OSL_CONSTEXPR u32 size() const _OSL_NOEXCEPT {
            return 2;
        }
    };
    
    typedef Point<unsigned, 2> Point2u;
    typedef Point<int,      2> Point2i;
    typedef Point<float,    2> Point2f;
    typedef Point<double,   2> Point2d;
}

#endif