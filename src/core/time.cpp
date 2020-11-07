#include <unified/core/time.hpp>

UNIFIED_BEGIN_NAMESPACE

Time::Time() _UNIFIED_NOEXCEPT : _microseconds(0) { }

Time::Time(u64 microseconds) _UNIFIED_NOEXCEPT : _microseconds(microseconds) { }

_UNIFIED_NODISCARD double Time::asSeconds() const {
    return static_cast<double>(_microseconds) / 1000000.0;
}

_UNIFIED_NODISCARD u32 Time::asMilliseconds() const {
    return static_cast<u32>(_microseconds / 1000);
}

_UNIFIED_NODISCARD u64 Time::asMicroseconds() const _UNIFIED_NOEXCEPT {
    return _microseconds;
}

_UNIFIED_NODISCARD bool Time::operator==(Time const &object) const _UNIFIED_NOEXCEPT {
    return asMicroseconds() == object.asMicroseconds();
}

_UNIFIED_NODISCARD bool Time::operator!=(Time const &object) const _UNIFIED_NOEXCEPT {
    return asMicroseconds() != object.asMicroseconds();
}

_UNIFIED_NODISCARD bool Time::operator>(Time const &object) _UNIFIED_NOEXCEPT {
    return _microseconds > object.asMicroseconds();
}

_UNIFIED_NODISCARD bool Time::operator<(Time const &object) _UNIFIED_NOEXCEPT {
    return _microseconds < object.asMicroseconds();
}

_UNIFIED_NODISCARD bool Time::operator>=(Time const &object) _UNIFIED_NOEXCEPT {
    return _microseconds >= object.asMicroseconds();
}

_UNIFIED_NODISCARD bool Time::operator<=(Time const &object) _UNIFIED_NOEXCEPT {
    return _microseconds <= object.asMicroseconds();
}

_UNIFIED_NODISCARD Time Time::operator+(Time const &object) _UNIFIED_NOEXCEPT {
    return Time(_microseconds + object.asMicroseconds());
}

Time Time::operator+=(Time const &object) _UNIFIED_NOEXCEPT {
    _microseconds += object.asMicroseconds();
    return *this;
}

_UNIFIED_NODISCARD Time Time::operator-(Time const &object) _UNIFIED_NOEXCEPT {
    return Time(_microseconds - object.asMicroseconds());
}

Time Time::operator-=(Time const &object) _UNIFIED_NOEXCEPT {
    _microseconds -= object.asMicroseconds();
    return *this;
}

_UNIFIED_NODISCARD Time Time::operator*(Time const &object) _UNIFIED_NOEXCEPT {
    return Time(_microseconds * object.asMicroseconds());
}

Time Time::operator*=(Time const &object) _UNIFIED_NOEXCEPT {
    _microseconds *= object.asMicroseconds();
    return *this;
}

_UNIFIED_NODISCARD Time Time::operator/(Time const &object) _UNIFIED_NOEXCEPT {
    return Time(_microseconds / object.asMicroseconds());
}

Time Time::operator/=(Time const &object) _UNIFIED_NOEXCEPT {
    _microseconds /= object.asMicroseconds();
    return *this;
}

_UNIFIED_NODISCARD Time seconds(double count) {
    return Time(static_cast<u64>(count * 1000000.0));
}

_UNIFIED_NODISCARD Time milliseconds(u32 count) {
    return Time(static_cast<u64>(count) * 1000);
}

_UNIFIED_NODISCARD Time microseconds(u64 count) _UNIFIED_NOEXCEPT {
    return Time(count);
}

UNIFIED_END_NAMESPACE
