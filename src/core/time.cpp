#include <unified/core/time.hpp>

#include <chrono>
using namespace std;

UNIFIED_BEGIN_NAMESPACE

Time::Time() : _microseconds(0) { }

Time::Time(u64 microseconds) : _microseconds(microseconds) { }

UNIFIED_NODISCARD double Time::asSeconds() const {
    return static_cast<double>(_microseconds) / 1000000.0;
}

UNIFIED_NODISCARD u32 Time::asMilliseconds() const {
    return static_cast<u32>(_microseconds / 1000);
}

UNIFIED_NODISCARD u64 Time::asMicroseconds() const {
    return _microseconds;
}

UNIFIED_NODISCARD bool Time::operator==(const Time &object) const {
    return asMicroseconds() == object.asMicroseconds();
}

UNIFIED_NODISCARD bool Time::operator!=(const Time &object) const {
    return asMicroseconds() != object.asMicroseconds();
}

UNIFIED_NODISCARD bool Time::operator>(const Time &object) {
    return _microseconds > object.asMicroseconds();
}

UNIFIED_NODISCARD bool Time::operator<(const Time &object) {
    return _microseconds < object.asMicroseconds();
}

UNIFIED_NODISCARD bool Time::operator>=(const Time &object) {
    return _microseconds >= object.asMicroseconds();
}

UNIFIED_NODISCARD bool Time::operator<=(const Time &object) {
    return _microseconds <= object.asMicroseconds();
}

UNIFIED_NODISCARD Time Time::operator+(const Time &object) {
    return Time(_microseconds + object.asMicroseconds());
}

Time Time::operator+=(const Time &object) {
    _microseconds += object.asMicroseconds();
    return *this;
}

UNIFIED_NODISCARD Time Time::operator-(const Time &object) {
    return Time(_microseconds - object.asMicroseconds());
}

Time Time::operator-=(const Time &object) {
    _microseconds -= object.asMicroseconds();
    return *this;
}

UNIFIED_NODISCARD Time Time::operator*(const Time &object) {
    return Time(_microseconds * object.asMicroseconds());
}

Time Time::operator*=(const Time &object) {
    _microseconds *= object.asMicroseconds();
    return *this;
}

UNIFIED_NODISCARD Time Time::operator/(const Time &object) {
    return Time(_microseconds / object.asMicroseconds());
}

Time Time::operator/=(const Time &object) {
    _microseconds /= object.asMicroseconds();
    return *this;
}

UNIFIED_NODISCARD Time seconds(double count) {
    return Time(static_cast<u64>(count * 1000000.0));
}

UNIFIED_NODISCARD Time milliseconds(u32 count) {
    return Time(static_cast<u64>(count) * 1000);
}

UNIFIED_NODISCARD Time microseconds(u64 count) {
    return Time(count);
}

UNIFIED_NODISCARD Time get_current_time() {
    return microseconds(chrono::duration_cast<chrono::microseconds>(
        chrono::system_clock::now().time_since_epoch()
    ).count());
}

UNIFIED_END_NAMESPACE
