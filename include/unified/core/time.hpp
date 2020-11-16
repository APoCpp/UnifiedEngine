#ifndef _UNIFIED_CORE_TIME_HPP
#define _UNIFIED_CORE_TIME_HPP

# include <unified/core/int_types.hpp>

UNIFIED_BEGIN_NAMESPACE

class Time
{
public:

    Time();
    explicit Time(u64 microseconds);

    UNIFIED_NODISCARD double asSeconds() const;
    UNIFIED_NODISCARD u32 asMilliseconds() const;
    UNIFIED_NODISCARD u64 asMicroseconds() const;

    UNIFIED_NODISCARD bool operator==(const Time &object) const;
    UNIFIED_NODISCARD bool operator!=(const Time &object) const;

    UNIFIED_NODISCARD bool operator>(const Time &object);
    UNIFIED_NODISCARD bool operator<(const Time &object);

    UNIFIED_NODISCARD bool operator>=(const Time &object);
    UNIFIED_NODISCARD bool operator<=(const Time &object);

    UNIFIED_NODISCARD Time operator+(const Time &object);
    Time operator+=(const Time &object);

    UNIFIED_NODISCARD Time operator-(const Time &object);
    Time operator-=(const Time &object);

    UNIFIED_NODISCARD Time operator*(const Time &object);
    Time operator*=(const Time &object);

    UNIFIED_NODISCARD Time operator/(const Time &object);
    Time operator/=(const Time &object);

protected:

    u64 _microseconds;

};

UNIFIED_NODISCARD Time seconds(double count);
UNIFIED_NODISCARD Time milliseconds(u32 count);
UNIFIED_NODISCARD Time microseconds(u64 count);

UNIFIED_NODISCARD Time get_current_time();

UNIFIED_END_NAMESPACE

#endif
