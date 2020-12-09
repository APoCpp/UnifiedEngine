#ifndef _UNIFIED_CORE_MATH_POINT3_HPP
#define _UNIFIED_CORE_MATH_POINT3_HPP

# include <unified/core/math/point_fwd.hpp>
# include <fmt/format.h>

UNIFIED_BEGIN_NAMESPACE

template <class _type>
struct Point<_type, 3>
{
    _type x, y, z;

    UNIFIED_CONSTEXPR Point() : x(_type()), y(_type()), z(_type()) { }
    UNIFIED_CONSTEXPR Point(_type xyz) : x(xyz), y(xyz), z(xyz) { }
    UNIFIED_CONSTEXPR Point(_type x, _type y, _type z) : x(x), y(y), z(z) { }

    UNIFIED_CONSTEXPR _type operator[](u32 i) const {
        UNIFIED_CONSTEXPR _type Point::*accessors[] = {
            &Point::x,
            &Point::y,
            &Point::z
        };
        return this->*accessors[i];
    }

    UNIFIED_CONSTEXPR _type &operator[](u32 i) {
        UNIFIED_CONSTEXPR _type Point::*accessors[] = {
            &Point::x,
            &Point::y,
            &Point::z
        };
        return this->*accessors[i];
    }

    UNIFIED_CONSTEXPR Point operator+(const _type &r) const {
        return Point(x + r, y + r, z + r);
    }

    UNIFIED_CONSTEXPR Point operator+(const Point &r) const {
        return Point(x + r.x, y + r.y, z + r.z);
    }

    UNIFIED_CONSTEXPR Point operator-(const _type &r) const {
        return Point(x - r, y - r, z - r);
    }

    UNIFIED_CONSTEXPR Point operator-(const Point &r) const {
        return Point(x - r.x, y - r.y, z - r.z);
    }

    UNIFIED_CONSTEXPR Point operator*(const _type &r) const {
        return Point(x * r, y * r, z * r);
    }

    UNIFIED_CONSTEXPR Point operator*(const Point &r) const {
        return Point(x * r.x, y * r.y, z * r.z);
    }

    UNIFIED_CONSTEXPR Point operator/(const _type &r) const {
        return Point(x / r, y / r, z / r);
    }

    UNIFIED_CONSTEXPR Point operator/(const Point &r) const {
        return Point(x / r.x, y / r.y, z / r.z);
    }

    UNIFIED_CONSTEXPR Point &operator+=(const _type &r) {
        x += r, y += r, z += r;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator+=(const Point &r) {
        x += r.x, y += r.y, z += r.z;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator-=(const _type &r) {
        x -= r, y -= r, z -= r;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator-=(const Point &r) {
        x -= r.x, y -= r.y, z -= r.z;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator*=(const _type &r) {
        x *= r, y *= r, z *= r;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator*=(const Point &r) {
        x *= r.x, y *= r.y, z *= r.z;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator/=(const _type &r) {
        x /= r, y /= r, z /= r;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator/=(const Point &r) {
        x /= r.x, y /= r.y, z /= r.z;
        return *this;
    }

    UNIFIED_FORCE_INLINE u32 size() const {
        return 3;
    }
};

typedef Point<unsigned, 3> Point3u;
typedef Point<int,      3> Point3i;
typedef Point<float,    3> Point3f;
typedef Point<double,   3> Point3d;

UNIFIED_END_NAMESPACE

namespace fmt
{
    template <class _type> struct formatter<UNIFIED_NAMESPACE::Point<_type, 3>> : formatter<std::string> {
        template <class FormatContext>
        auto format(const UNIFIED_NAMESPACE::Point<_type, 3> &point, FormatContext &ctx) {
            return formatter<std::string>::format(fmt::format("{{ {}, {}, {} }}", point.x, point.y, point.z), ctx);
        }
    };
}

#endif
