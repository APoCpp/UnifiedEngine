#ifndef UNIFIED_CORE_MATH_POINT3_HPP
#define UNIFIED_CORE_MATH_POINT3_HPP

#include <unified/core/math/point_fwd.hpp>
#include <fmt/format.h>

UNIFIED_BEGIN_NAMESPACE

template <class _type>
struct Point<_type, 3>
{
    _type x, y, z;

    _UNIFIED_CONSTEXPR Point() _UNIFIED_NOEXCEPT : x(_type()), y(_type()), z(_type()) { }
    _UNIFIED_CONSTEXPR Point(_type xyz) _UNIFIED_NOEXCEPT : x(xyz), y(xyz), z(xyz) { }
    _UNIFIED_CONSTEXPR Point(_type const x, _type const y, _type const z) _UNIFIED_NOEXCEPT : x(x), y(y), z(z) { }

    _UNIFIED_CONSTEXPR _type operator[](u32 i) const _UNIFIED_NOEXCEPT {
        _UNIFIED_CONSTEXPR _type Point::*accessors[] = {
            &Point::x,
            &Point::y,
            &Point::z
        };
        return this->*accessors[i];
    }

    _UNIFIED_CONSTEXPR _type &operator[](u32 i) _UNIFIED_NOEXCEPT {
        _UNIFIED_CONSTEXPR _type Point::*accessors[] = {
            &Point::x,
            &Point::y,
            &Point::z
        };
        return this->*accessors[i];
    }

    _UNIFIED_CONSTEXPR Point operator+(_type const &r) const _UNIFIED_NOEXCEPT {
        return Point(x + r, y + r, z + r);
    }

    _UNIFIED_CONSTEXPR Point operator+(Point const &r) const _UNIFIED_NOEXCEPT {
        return Point(x + r.x, y + r.y, z + r.z);
    }

    _UNIFIED_CONSTEXPR Point operator-(_type const &r) const _UNIFIED_NOEXCEPT {
        return Point(x - r, y - r, z - r);
    }

    _UNIFIED_CONSTEXPR Point operator-(Point const &r) const _UNIFIED_NOEXCEPT {
        return Point(x - r.x, y - r.y, z - r.z);
    }

    _UNIFIED_CONSTEXPR Point operator*(_type const &r) const _UNIFIED_NOEXCEPT {
        return Point(x * r, y * r, z * r);
    }

    _UNIFIED_CONSTEXPR Point operator*(Point const &r) const _UNIFIED_NOEXCEPT {
        return Point(x * r.x, y * r.y, z * r.z);
    }

    _UNIFIED_CONSTEXPR Point operator/(_type const &r) const _UNIFIED_NOEXCEPT {
        return Point(x / r, y / r, z / r);
    }

    _UNIFIED_CONSTEXPR Point operator/(Point const &r) const _UNIFIED_NOEXCEPT {
        return Point(x / r.x, y / r.y, z / r.z);
    }

    _UNIFIED_CONSTEXPR Point &operator+=(_type const &r) _UNIFIED_NOEXCEPT {
        x += r, y += r, z += r;
        return *this;
    }

    _UNIFIED_CONSTEXPR Point &operator+=(Point const &r) _UNIFIED_NOEXCEPT {
        x += r.x, y += r.y, z += r.z;
        return *this;
    }

    _UNIFIED_CONSTEXPR Point &operator-=(_type const &r) _UNIFIED_NOEXCEPT {
        x -= r, y -= r, z -= r;
        return *this;
    }

    _UNIFIED_CONSTEXPR Point &operator-=(Point const &r) _UNIFIED_NOEXCEPT {
        x -= r.x, y -= r.y, z -= r.z;
        return *this;
    }

    _UNIFIED_CONSTEXPR Point &operator*=(_type const &r) _UNIFIED_NOEXCEPT {
        x *= r, y *= r, z *= r;
        return *this;
    }

    _UNIFIED_CONSTEXPR Point &operator*=(Point const &r) _UNIFIED_NOEXCEPT {
        x *= r.x, y *= r.y, z *= r.z;
        return *this;
    }

    _UNIFIED_CONSTEXPR Point &operator/=(_type const &r) _UNIFIED_NOEXCEPT {
        x /= r, y /= r, z /= r;
        return *this;
    }

    _UNIFIED_CONSTEXPR Point &operator/=(Point const &r) _UNIFIED_NOEXCEPT {
        x /= r.x, y /= r.y, z /= r.z;
        return *this;
    }

    _UNIFIED_CONSTEXPR u32 size() const _UNIFIED_NOEXCEPT {
        return 3;
    }
};

typedef Point<unsigned, 3> Point3u;
typedef Point<int,      3> Point3i;
typedef Point<float,    3> Point3f;
typedef Point<double,   3> Point3d;

UNIFIED_END_NAMESPACE

template <class _type> struct fmt::formatter<UNIFIED_NAMESPACE::Point<_type, 3>> : fmt::formatter<std::string> {
    template <class FormatContext>
    auto format(const UNIFIED_NAMESPACE::Point<_type, 3> &vector, FormatContext &ctx) {
        return formatter<std::string>::format(fmt::format("{{ {}, {}, {} }}", vector.x, vector.y, vector.z), ctx);
    }
};

#endif
