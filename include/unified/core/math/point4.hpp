#ifndef UNIFIED_CORE_MATH_POINT4_HPP
#define UNIFIED_CORE_MATH_POINT4_HPP

#include <unified/core/math/point_fwd.hpp>
#include <fmt/format.h>

UNIFIED_BEGIN_NAMESPACE

template <class _type>
struct Point<_type, 4>
{
    _type x, y, z, w;

    _UNIFIED_CONSTEXPR Point() _UNIFIED_NOEXCEPT : x(_type()), y(_type()), z(_type()), w(_type()) { }
    _UNIFIED_CONSTEXPR Point(_type xyzw) _UNIFIED_NOEXCEPT : x(xyzw), y(xyzw), z(xyzw), w(xyzw) { }
    _UNIFIED_CONSTEXPR Point(_type const x, _type const y, _type const z, _type const w) _UNIFIED_NOEXCEPT : x(x), y(y), z(z), w(w) { }

    _UNIFIED_CONSTEXPR _type operator[](u32 i) const _UNIFIED_NOEXCEPT {
        _UNIFIED_CONSTEXPR _type Point::*accessors[] = {
            &Point::x,
            &Point::y,
            &Point::z,
            &Point::w
        };
        return this->*accessors[i];
    }

    _UNIFIED_CONSTEXPR _type &operator[](u32 i) _UNIFIED_NOEXCEPT {
        _UNIFIED_CONSTEXPR _type Point::*accessors[] = {
            &Point::x,
            &Point::y,
            &Point::z,
            &Point::w
        };
        return this->*accessors[i];
    }

    _UNIFIED_CONSTEXPR Point operator+(_type const &r) const _UNIFIED_NOEXCEPT {
        return Point(x + r, y + r, z + r, w + r);
    }

    _UNIFIED_CONSTEXPR Point operator+(Point const &r) const _UNIFIED_NOEXCEPT {
        return Point(x + r.x, y + r.y, z + r.z, w + r.w);
    }

    _UNIFIED_CONSTEXPR Point operator-(_type const &r) const _UNIFIED_NOEXCEPT {
        return Point(x - r, y - r, z - r, w - r);
    }

    _UNIFIED_CONSTEXPR Point operator-(Point const &r) const _UNIFIED_NOEXCEPT {
        return Point(x - r.x, y - r.y, z - r.z, w - r.w);
    }

    _UNIFIED_CONSTEXPR Point operator*(_type const &r) const _UNIFIED_NOEXCEPT {
        return Point(x * r, y * r, z * r, w * r);
    }

    _UNIFIED_CONSTEXPR Point operator*(Point const &r) const _UNIFIED_NOEXCEPT {
        return Point(x * r.x, y * r.y, z * r.z, w * r.w);
    }

    _UNIFIED_CONSTEXPR Point operator/(_type const &r) const _UNIFIED_NOEXCEPT {
        return Point(x / r, y / r, z / r, w / r);
    }

    _UNIFIED_CONSTEXPR Point operator/(Point const &r) const _UNIFIED_NOEXCEPT {
        return Point(x / r.x, y / r.y, z / r.z, w / r.w);
    }

    _UNIFIED_CONSTEXPR Point &operator+=(_type const &r) _UNIFIED_NOEXCEPT {
        x += r, y += r, z += r, w += r;
        return *this;
    }

    _UNIFIED_CONSTEXPR Point &operator+=(Point const &r) _UNIFIED_NOEXCEPT {
        x += r.x, y += r.y, z += r.z, w += r.w;
        return *this;
    }

    _UNIFIED_CONSTEXPR Point &operator-=(_type const &r) _UNIFIED_NOEXCEPT {
        x -= r, y -= r, z -= r, w -= r;
        return *this;
    }

    _UNIFIED_CONSTEXPR Point &operator-=(Point const &r) _UNIFIED_NOEXCEPT {
        x -= r.x, y -= r.y, z -= r.z, w -= r.w;
        return *this;
    }

    _UNIFIED_CONSTEXPR Point &operator*=(_type const &r) _UNIFIED_NOEXCEPT {
        x *= r, y *= r, z *= r, w *= r;
        return *this;
    }

    _UNIFIED_CONSTEXPR Point &operator*=(Point const &r) _UNIFIED_NOEXCEPT {
        x *= r.x, y *= r.y, z *= r.z, w *= r.w;
        return *this;
    }

    _UNIFIED_CONSTEXPR Point &operator/=(_type const &r) _UNIFIED_NOEXCEPT {
        x /= r, y /= r, z /= r, w /= r;
        return *this;
    }

    _UNIFIED_CONSTEXPR Point &operator/=(Point const &r) _UNIFIED_NOEXCEPT {
        x /= r.x, y /= r.y, z /= r.z, w /= r.w;
        return *this;
    }

    _UNIFIED_CONSTEXPR u32 size() const _UNIFIED_NOEXCEPT {
        return 4;
    }
};

typedef Point<unsigned, 4> Point4u;
typedef Point<int,      4> Point4i;
typedef Point<float,    4> Point4f;
typedef Point<double,   4> Point4d;

UNIFIED_END_NAMESPACE

template <class _type> struct fmt::formatter<UNIFIED_NAMESPACE::Point<_type, 4>> : fmt::formatter<std::string> {
    template <class FormatContext>
    auto format(const UNIFIED_NAMESPACE::Point<_type, 4> &vector, FormatContext &ctx) {
        return formatter<std::string>::format(fmt::format("{{ {}, {}, {}, {} }}", vector.x, vector.y, vector.z, vector.w), ctx);
    }
};

#endif
