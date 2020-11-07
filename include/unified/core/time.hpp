#ifndef UNIFIED_CORE_TIME_HPP
#define UNIFIED_CORE_TIME_HPP

#include <unified/defines.hpp>
#include <unified/core/int_types.hpp>

UNIFIED_BEGIN_NAMESPACE

class Time
{
public:

    Time() _UNIFIED_NOEXCEPT;
    explicit Time(u64 microseconds) _UNIFIED_NOEXCEPT;

    _UNIFIED_NODISCARD double asSeconds() const;
    _UNIFIED_NODISCARD u32 asMilliseconds() const;
    _UNIFIED_NODISCARD u64 asMicroseconds() const _UNIFIED_NOEXCEPT;

    _UNIFIED_NODISCARD bool operator==(Time const &object) const _UNIFIED_NOEXCEPT;
    _UNIFIED_NODISCARD bool operator!=(Time const &object) const _UNIFIED_NOEXCEPT;

    _UNIFIED_NODISCARD bool operator>(Time const &object) _UNIFIED_NOEXCEPT;
    _UNIFIED_NODISCARD bool operator<(Time const &object) _UNIFIED_NOEXCEPT;

    _UNIFIED_NODISCARD bool operator>=(Time const &object) _UNIFIED_NOEXCEPT;
    _UNIFIED_NODISCARD bool operator<=(Time const &object) _UNIFIED_NOEXCEPT;

    _UNIFIED_NODISCARD Time operator+(Time const &object) _UNIFIED_NOEXCEPT;
    Time operator+=(Time const &object) _UNIFIED_NOEXCEPT;

    _UNIFIED_NODISCARD Time operator-(Time const &object) _UNIFIED_NOEXCEPT;
    Time operator-=(Time const &object) _UNIFIED_NOEXCEPT;

    _UNIFIED_NODISCARD Time operator*(Time const &object) _UNIFIED_NOEXCEPT;
    Time operator*=(Time const &object) _UNIFIED_NOEXCEPT;

    _UNIFIED_NODISCARD Time operator/(Time const &object) _UNIFIED_NOEXCEPT;
    Time operator/=(Time const &object) _UNIFIED_NOEXCEPT;

protected:

    u64 _microseconds;

};

_UNIFIED_NODISCARD Time seconds(double count);
_UNIFIED_NODISCARD Time milliseconds(u32 count);
_UNIFIED_NODISCARD Time microseconds(u64 count) _UNIFIED_NOEXCEPT;

UNIFIED_END_NAMESPACE

#endif
