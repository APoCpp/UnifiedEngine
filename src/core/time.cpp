#include <unified/core/time.hpp>

Unified::Time::Time() _OSL_NOEXCEPT : _microseconds(0) { }

Unified::Time::Time(u64 microseconds) _OSL_NOEXCEPT : _microseconds(microseconds) { }

_OSL_NODISCARD double Unified::Time::asSeconds() const {
    return static_cast<double>(_microseconds) / 1000000.0;
}

_OSL_NODISCARD u32 Unified::Time::asMilliseconds() const {
    return static_cast<u32>(_microseconds / 1000);
}

_OSL_NODISCARD u64 Unified::Time::asMicroseconds() const _OSL_NOEXCEPT {
    return _microseconds;
}

_OSL_NODISCARD Unified::Time Unified::seconds(double count) {
    return Time(static_cast<u64>(count * 1000000.0));
}

_OSL_NODISCARD Unified::Time Unified::milliseconds(u32 count) {
    return Time(static_cast<u64>(count) * 1000);
}

_OSL_NODISCARD Unified::Time Unified::microseconds(u64 count) _OSL_NOEXCEPT {
    return Time(count);
}

_OSL_NODISCARD bool Unified::Time::operator==(Time const &object) const _OSL_NOEXCEPT {
    return asMicroseconds() == object.asMicroseconds();
}

_OSL_NODISCARD bool Unified::Time::operator!=(Time const &object) const _OSL_NOEXCEPT {
    return asMicroseconds() != object.asMicroseconds();
}

_OSL_NODISCARD bool Unified::Time::operator>(Time const &object) _OSL_NOEXCEPT {
    return _microseconds > object.asMicroseconds();
}

_OSL_NODISCARD bool Unified::Time::operator<(Time const &object) _OSL_NOEXCEPT {
    return _microseconds < object.asMicroseconds();
}

_OSL_NODISCARD bool Unified::Time::operator>=(Time const &object) _OSL_NOEXCEPT {
    return _microseconds >= object.asMicroseconds();
}

_OSL_NODISCARD bool Unified::Time::operator<=(Time const &object) _OSL_NOEXCEPT {
    return _microseconds <= object.asMicroseconds();
}

_OSL_NODISCARD Unified::Time Unified::Time::operator+(Time const &object) _OSL_NOEXCEPT {
    return Time(_microseconds + object.asMicroseconds());
}

Unified::Time Unified::Time::operator+=(Time const &object) _OSL_NOEXCEPT {
    _microseconds += object.asMicroseconds();
    return *this;
}

_OSL_NODISCARD Unified::Time Unified::Time::operator-(Time const &object) _OSL_NOEXCEPT {
    return Time(_microseconds - object.asMicroseconds());
}

Unified::Time Unified::Time::operator-=(Time const &object) _OSL_NOEXCEPT {
    _microseconds -= object.asMicroseconds();
    return *this;
}

_OSL_NODISCARD Unified::Time Unified::Time::operator*(Time const &object) _OSL_NOEXCEPT {
    return Time(_microseconds * object.asMicroseconds());
}

Unified::Time Unified::Time::operator*=(Time const &object) _OSL_NOEXCEPT {
    _microseconds *= object.asMicroseconds();
    return *this;
}

_OSL_NODISCARD Unified::Time Unified::Time::operator/(Time const &object) _OSL_NOEXCEPT {
    return Time(_microseconds / object.asMicroseconds());
}

Unified::Time Unified::Time::operator/=(Time const &object) _OSL_NOEXCEPT {
    _microseconds /= object.asMicroseconds();
    return *this;
}