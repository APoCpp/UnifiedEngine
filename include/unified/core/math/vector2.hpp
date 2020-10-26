#ifndef UNIFIED_CORE_MATH_VECTOR2_HPP
#define UNIFIED_CORE_MATH_VECTOR2_HPP

#include <unified/defines.hpp>
#include <unified/core/math/vector_fwd.hpp>
#include <defines.hpp>

UNIFIED_BEGIN_NAMESPACE

template <class _type>
struct Vector<_type, 2>
{
    _type x, y;

    Vector() _OSL_NOEXCEPT : x(_type()), y(_type()) { }
    Vector(_type xy) _OSL_NOEXCEPT : x(xy), y(xy) { }
    Vector(_type x, _type y) _OSL_NOEXCEPT : x(x), y(y) { }

    _type operator[](u32 i) const _OSL_NOEXCEPT {
        _OSL_CONSTEXPR _type Vector::*accessors[] = {
            &Vector::x,
            &Vector::y
        };
        return this->*accessors[i];
    }

    _type &operator[](u32 i) _OSL_NOEXCEPT {
        _OSL_CONSTEXPR _type Vector::*accessors[] = {
            &Vector::x,
            &Vector::y
        };
        return this->*accessors[i];
    }

    _OSL_CONSTEXPR Vector operator+(_type const &r) const _OSL_NOEXCEPT {
        return Vector(x + r, y + r);
    }

    _OSL_CONSTEXPR Vector operator+(Vector const &r) const _OSL_NOEXCEPT {
        return Vector(x + r.x, y + r.y);
    }

    _OSL_CONSTEXPR Vector operator-(_type const &r) const _OSL_NOEXCEPT {
        return Vector(x - r, y - r);
    }

    _OSL_CONSTEXPR Vector operator-(Vector const &r) const _OSL_NOEXCEPT {
        return Vector(x - r.x, y - r.y);
    }

    _OSL_CONSTEXPR Vector operator*(_type const &r) const _OSL_NOEXCEPT {
        return Vector(x * r, y * r);
    }

    _OSL_CONSTEXPR Vector operator*(Vector const &r) const _OSL_NOEXCEPT {
        return Vector(x * r.x, y * r.y);
    }

    _OSL_CONSTEXPR Vector operator/(_type const &r) const _OSL_NOEXCEPT {
        return Vector(x / r, y / r);
    }

    _OSL_CONSTEXPR Vector operator/(Vector const &r) const _OSL_NOEXCEPT {
        return Vector(x / r.x, y / r.y);
    }

    _OSL_CONSTEXPR Vector &operator+=(_type const &r) _OSL_NOEXCEPT {
        x += r, y += r;
        return *this;
    }

    _OSL_CONSTEXPR Vector &operator+=(Vector const &r) _OSL_NOEXCEPT {
        x += r.x, y += r.y;
        return *this;
    }

    _OSL_CONSTEXPR Vector &operator-=(_type const &r) _OSL_NOEXCEPT {
        x -= r, y -= r;
        return *this;
    }

    _OSL_CONSTEXPR Vector &operator-=(Vector const &r) _OSL_NOEXCEPT {
        x -= r.x, y -= r.y;
        return *this;
    }

    _OSL_CONSTEXPR Vector &operator*=(_type const &r) _OSL_NOEXCEPT {
        x *= r, y *= r;
        return *this;
    }

    _OSL_CONSTEXPR Vector &operator*=(Vector const &r) _OSL_NOEXCEPT {
        x *= r.x, y *= r.y;
        return *this;
    }

    _OSL_CONSTEXPR Vector &operator/=(_type const &r) _OSL_NOEXCEPT {
        x /= r, y /= r;
        return *this;
    }

    _OSL_CONSTEXPR Vector &operator/=(Vector const &r) _OSL_NOEXCEPT {
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

typedef Vector<unsigned, 2> Vector2u;
typedef Vector<int,      2> Vector2i;
typedef Vector<float,    2> Vector2f;
typedef Vector<double,   2> Vector2d;

UNIFIED_END_NAMESPACE

#endif
