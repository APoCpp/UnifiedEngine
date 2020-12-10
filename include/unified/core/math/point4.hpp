#ifndef _UNIFIED_CORE_MATH_POINT4_HPP
#define _UNIFIED_CORE_MATH_POINT4_HPP

# include <unified/core/math/point_fwd.hpp>
# include <fmt/format.h>

UNIFIED_BEGIN_NAMESPACE

template <class _type>
struct Point<_type, 4>
{
    _type x, y, z, w;

    UNIFIED_CONSTEXPR Point() : x(_type()), y(_type()), z(_type()), w(_type()) { }
    UNIFIED_CONSTEXPR Point(_type xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) { }
    UNIFIED_CONSTEXPR Point(_type x, _type y, _type z, _type w) : x(x), y(y), z(z), w(w) { }

    UNIFIED_CONSTEXPR _type operator[](u32 i) const {
        UNIFIED_CONSTEXPR _type Point::*accessors[] = {
            &Point::x,
            &Point::y,
            &Point::z,
            &Point::w
        };
        return this->*accessors[i];
    }

    UNIFIED_CONSTEXPR _type &operator[](u32 i) {
        UNIFIED_CONSTEXPR _type Point::*accessors[] = {
            &Point::x,
            &Point::y,
            &Point::z,
            &Point::w
        };
        return this->*accessors[i];
    }

    UNIFIED_CONSTEXPR bool operator==(const _type &r) const {
        return this->x == r && this->y == r && this->z == r && this->w == r;
    }

    UNIFIED_CONSTEXPR bool operator==(const Point &r) const {
        return this->x == r.x && this->y == r.y && this->z == r.z && this->w == r.w;
    }

    UNIFIED_CONSTEXPR bool operator!=(const _type &r) const {
        return !this->operator==(r);
    }

    UNIFIED_CONSTEXPR bool operator!=(const Point &r) const {
        return !this->operator==(r);
    }

    UNIFIED_CONSTEXPR Point operator+(const _type &r) const {
        return Point(x + r, y + r, z + r, w + r);
    }

    UNIFIED_CONSTEXPR Point operator+(const Point &r) const {
        return Point(x + r.x, y + r.y, z + r.z, w + r.w);
    }

    UNIFIED_CONSTEXPR Point operator-(const _type &r) const {
        return Point(x - r, y - r, z - r, w - r);
    }

    UNIFIED_CONSTEXPR Point operator-(const Point &r) const {
        return Point(x - r.x, y - r.y, z - r.z, w - r.w);
    }

    UNIFIED_CONSTEXPR Point operator*(const _type &r) const {
        return Point(x * r, y * r, z * r, w * r);
    }

    UNIFIED_CONSTEXPR Point operator*(const Point &r) const {
        return Point(x * r.x, y * r.y, z * r.z, w * r.w);
    }

    UNIFIED_CONSTEXPR Point operator/(const _type &r) const {
        return Point(x / r, y / r, z / r, w / r);
    }

    UNIFIED_CONSTEXPR Point operator/(const Point &r) const {
        return Point(x / r.x, y / r.y, z / r.z, w / r.w);
    }

    UNIFIED_CONSTEXPR Point &operator+=(const _type &r) {
        x += r, y += r, z += r, w += r;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator+=(const Point &r) {
        x += r.x, y += r.y, z += r.z, w += r.w;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator-=(const _type &r) {
        x -= r, y -= r, z -= r, w -= r;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator-=(const Point &r) {
        x -= r.x, y -= r.y, z -= r.z, w -= r.w;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator*=(const _type &r) {
        x *= r, y *= r, z *= r, w *= r;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator*=(const Point &r) {
        x *= r.x, y *= r.y, z *= r.z, w *= r.w;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator/=(const _type &r) {
        x /= r, y /= r, z /= r, w /= r;
        return *this;
    }

    UNIFIED_CONSTEXPR Point &operator/=(const Point &r) {
        x /= r.x, y /= r.y, z /= r.z, w /= r.w;
        return *this;
    }

    UNIFIED_FORCE_INLINE u32 size() const {
        return 4;
    }
};

typedef Point<unsigned, 4> Point4u;
typedef Point<int,      4> Point4i;
typedef Point<float,    4> Point4f;
typedef Point<double,   4> Point4d;

UNIFIED_END_NAMESPACE

namespace fmt
{
    template <class _type> struct formatter<UNIFIED_NAMESPACE::Point<_type, 4>> : formatter<std::string> {
        template <class FormatContext>
        auto format(const UNIFIED_NAMESPACE::Point<_type, 4> &point, FormatContext &ctx) {
            return formatter<std::string>::format(fmt::format("{{ {}, {}, {}, {} }}", point.x, point.y, point.z, point.w), ctx);
        }
    };
}

#endif
