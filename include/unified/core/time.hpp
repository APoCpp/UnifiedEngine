#include <unified/defines.hpp>

#ifndef UNIFIED_CORE_TIME_HPP
#define UNIFIED_CORE_TIME_HPP

#include <inttypes.hpp>
#include <defines.hpp>

UNIFIED_BEGIN_NAMESPACE

class Time
{
public:

    Time() _OSL_NOEXCEPT;
    explicit Time(u64 microseconds) _OSL_NOEXCEPT;

    _OSL_NODISCARD double asSeconds() const;
    _OSL_NODISCARD u32 asMilliseconds() const;
    _OSL_NODISCARD u64 asMicroseconds() const _OSL_NOEXCEPT;

    _OSL_NODISCARD bool operator==(Time const &object) const _OSL_NOEXCEPT;
    _OSL_NODISCARD bool operator!=(Time const &object) const _OSL_NOEXCEPT;

    _OSL_NODISCARD bool operator>(Time const &object) _OSL_NOEXCEPT;
    _OSL_NODISCARD bool operator<(Time const &object) _OSL_NOEXCEPT;

    _OSL_NODISCARD bool operator>=(Time const &object) _OSL_NOEXCEPT;
    _OSL_NODISCARD bool operator<=(Time const &object) _OSL_NOEXCEPT;

    _OSL_NODISCARD Time operator+(Time const &object) _OSL_NOEXCEPT;
    Time operator+=(Time const &object) _OSL_NOEXCEPT;

    _OSL_NODISCARD Time operator-(Time const &object) _OSL_NOEXCEPT;
    Time operator-=(Time const &object) _OSL_NOEXCEPT;

    _OSL_NODISCARD Time operator*(Time const &object) _OSL_NOEXCEPT;
    Time operator*=(Time const &object) _OSL_NOEXCEPT;

    _OSL_NODISCARD Time operator/(Time const &object) _OSL_NOEXCEPT;
    Time operator/=(Time const &object) _OSL_NOEXCEPT;

protected:

    u64 _microseconds;

};

_OSL_NODISCARD Time seconds(double count);
_OSL_NODISCARD Time milliseconds(u32 count);
_OSL_NODISCARD Time microseconds(u64 count) _OSL_NOEXCEPT;

UNIFIED_END_NAMESPACE

#endif
