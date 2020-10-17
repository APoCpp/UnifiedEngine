#include <unified/core/math/vector_fwd.hpp>

#ifndef UNIFIED_CORE_VECTOR3_HPP
#define UNIFIED_CORE_VECTOR3_HPP

namespace Unified
{
    template <class _type>
    struct Vector<_type, 3>
    {
        _type x, y, z;

        Vector() : x(_type()), y(_type()), z(_type()) _OSL_NOEXCEPT { }
        Vector(const _type v[3]) : x(v[0]), y(v[1]), z(v[2]) _OSL_NOEXCEPT { }
        Vector(const _type x, const _type y, const _type z) : x(x), y(y), z(z) _OSL_NOEXCEPT { }

        _type operator[](uint32_t i) const _OSL_NOEXCEPT {
            _OSL_CONSTEXPR _type Vector::*accessors[] = {
                &Vector::x,
                &Vector::y,
                &Vector::z
            }; return this->*accessors[i];
        }

        _type &operator[](uint32_t i) _OSL_NOEXCEPT {
            _OSL_CONSTEXPR _type Vector::*accessors[] = {
                &Vector::x,
                &Vector::y,
                &Vector::z
            }; return this->*accessors[i];
        }

        _OSL_CONSTEXPR Vector operator+(const _type &r) const _OSL_NOEXCEPT {
            return Vector(x + r, y + r, z + r);
        }

        _OSL_CONSTEXPR Vector operator+(const Vector &r) const _OSL_NOEXCEPT {
            return Vector(x + r.x, y + r.y, z + r.z);
        }

        _OSL_CONSTEXPR Vector operator-(const _type &r) const _OSL_NOEXCEPT {
            return Vector(x - r, y - r, z - r);
        }

        _OSL_CONSTEXPR Vector operator-(const Vector &r) const _OSL_NOEXCEPT {
            return Vector(x - r.x, y - r.y, z - r.z);
        }

        _OSL_CONSTEXPR Vector operator*(const _type &r) const _OSL_NOEXCEPT {
            return Vector(x * r, y * r, z * r);
        }

        _OSL_CONSTEXPR Vector operator*(const Vector &r) const _OSL_NOEXCEPT {
            return Vector(x * r.x, y * r.y, z * r.z);
        }

        _OSL_CONSTEXPR Vector operator/(const _type &r) const _OSL_NOEXCEPT {
            return Vector(x / r, y / r, z / r);
        }

        _OSL_CONSTEXPR Vector operator/(const Vector &r) const _OSL_NOEXCEPT {
            return Vector(x / r.x, y / r.y, z / r.z);
        }

        _OSL_CONSTEXPR Vector &operator+=(const _type &r) const _OSL_NOEXCEPT {
            x += r, y += r, z += r;
            return *this;
        }

        _OSL_CONSTEXPR Vector &operator+=(const Vector &r) const _OSL_NOEXCEPT {
            x += r.x, y += r.y, z += r.z;
            return *this;
        }

        _OSL_CONSTEXPR Vector &operator-=(const _type &r) const _OSL_NOEXCEPT {
            x -= r, y -= r, z -= r;
            return *this;
        }

        _OSL_CONSTEXPR Vector &operator-=(const Vector &r) const _OSL_NOEXCEPT {
            x -= r.x, y -= r.y, z -= r.z;
            return *this;
        }

        _OSL_CONSTEXPR Vector &operator*=(const _type &r) const _OSL_NOEXCEPT {
            x *= r, y *= r, z *= r;
            return *this;
        }

        _OSL_CONSTEXPR Vector &operator*=(const Vector &r) const _OSL_NOEXCEPT {
            x *= r.x, y *= r.y, z *= r.z;
            return *this;
        }

        _OSL_CONSTEXPR Vector &operator/=(const _type &r) const _OSL_NOEXCEPT {
            x /= r, y /= r, z /= r;
            return *this;
        }

        _OSL_CONSTEXPR Vector &operator/=(const Vector &r) const _OSL_NOEXCEPT {
            x /= r.x, y /= r.y, z /= r.z;
            return *this;
        }

        _OSL__OSL_CONSTEXPR uint32_t size() const _OSL_NOEXCEPT {
            return 3;
        }
    };
    
    typedef Vector<unsigned, 3> Vector3u;
    typedef Vector<int,      3> Vector3i;
    typedef Vector<float,    3> Vector3f;
    typedef Vector<double,   3> Vector3d;
}

#endif