#ifndef UNIFIED_CORE_MATH_POINT3_HPP
#define UNIFIED_CORE_MATH_POINT3_HPP

#include <unified/core/math/point_fwd.hpp>

UNIFIED_BEGIN_NAMESPACE

template <class _type>
struct Point<_type, 3>
{
    _type x, y, z;

    Point() _OSL_NOEXCEPT : x(_type()), y(_type()), z(_type()) { }
    Point(const _type v[3]) _OSL_NOEXCEPT : x(v[0]), y(v[1]), z(v[2]) { }
    Point(const _type x, const _type y, const _type z) _OSL_NOEXCEPT : x(x), y(y), z(z) { }

    _type operator[](u32 i) const _OSL_NOEXCEPT {
        _OSL_CONSTEXPR _type Point::*accessors[] = {
            &Point::x,
            &Point::y,
            &Point::z
        };
        return this->*accessors[i];
    }

    _type &operator[](u32 i) _OSL_NOEXCEPT {
        _OSL_CONSTEXPR _type Point::*accessors[] = {
            &Point::x,
            &Point::y,
            &Point::z
        };
        return this->*accessors[i];
    }

    _OSL_CONSTEXPR Point operator+(_type const &r) const _OSL_NOEXCEPT {
        return Point(x + r, y + r, z + r);
    }

    _OSL_CONSTEXPR Point operator+(Point const &r) const _OSL_NOEXCEPT {
        return Point(x + r.x, y + r.y, z + r.z);
    }

    _OSL_CONSTEXPR Point operator-(_type const &r) const _OSL_NOEXCEPT {
        return Point(x - r, y - r, z - r);
    }

    _OSL_CONSTEXPR Point operator-(Point const &r) const _OSL_NOEXCEPT {
        return Point(x - r.x, y - r.y, z - r.z);
    }

    _OSL_CONSTEXPR Point operator*(_type const &r) const _OSL_NOEXCEPT {
        return Point(x * r, y * r, z * r);
    }

    _OSL_CONSTEXPR Point operator*(Point const &r) const _OSL_NOEXCEPT {
        return Point(x * r.x, y * r.y, z * r.z);
    }

    _OSL_CONSTEXPR Point operator/(_type const &r) const _OSL_NOEXCEPT {
        return Point(x / r, y / r, z / r);
    }

    _OSL_CONSTEXPR Point operator/(Point const &r) const _OSL_NOEXCEPT {
        return Point(x / r.x, y / r.y, z / r.z);
    }

    _OSL_CONSTEXPR Point &operator+=(_type const &r) _OSL_NOEXCEPT {
        x += r, y += r, z += r;
        return *this;
    }

    _OSL_CONSTEXPR Point &operator+=(Point const &r) _OSL_NOEXCEPT {
        x += r.x, y += r.y, z += r.z;
        return *this;
    }

    _OSL_CONSTEXPR Point &operator-=(_type const &r) _OSL_NOEXCEPT {
        x -= r, y -= r, z -= r;
        return *this;
    }

    _OSL_CONSTEXPR Point &operator-=(Point const &r) _OSL_NOEXCEPT {
        x -= r.x, y -= r.y, z -= r.z;
        return *this;
    }

    _OSL_CONSTEXPR Point &operator*=(_type const &r) _OSL_NOEXCEPT {
        x *= r, y *= r, z *= r;
        return *this;
    }

    _OSL_CONSTEXPR Point &operator*=(Point const &r) _OSL_NOEXCEPT {
        x *= r.x, y *= r.y, z *= r.z;
        return *this;
    }

    _OSL_CONSTEXPR Point &operator/=(_type const &r) _OSL_NOEXCEPT {
        x /= r, y /= r, z /= r;
        return *this;
    }

    _OSL_CONSTEXPR Point &operator/=(Point const &r) _OSL_NOEXCEPT {
        x /= r.x, y /= r.y, z /= r.z;
        return *this;
    }

    _OSL_CONSTEXPR u32 size() const _OSL_NOEXCEPT {
        return 3;
    }
};

typedef Point<unsigned, 3> Point3u;
typedef Point<int,      3> Point3i;
typedef Point<float,    3> Point3f;
typedef Point<double,   3> Point3d;

UNIFIED_END_NAMESPACE

#endif
