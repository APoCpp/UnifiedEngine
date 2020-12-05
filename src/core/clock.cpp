#include <unified/core/clock.hpp>

UNIFIED_BEGIN_NAMESPACE

Clock::Clock() {
    restart();
}

UNIFIED_NODISCARD Time Clock::get_elapsed_time() const {
    return get_current_time() - _timestamp;
}

Time Clock::restart() {
    return _timestamp = get_current_time();
}

UNIFIED_END_NAMESPACE
