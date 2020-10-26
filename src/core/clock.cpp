#include <unified/core/clock.hpp>
#include <GLFW/glfw3.h>

UNIFIED_BEGIN_NAMESPACE

Clock::Clock() { restart(); }

Time Clock::get_elapsed_time() const _OSL_NOEXCEPT {
    return seconds(glfwGetTime()) - _timestamp;
}

Time Clock::restart() _OSL_NOEXCEPT {
    _timestamp = seconds(glfwGetTime());
    return _timestamp;
}

UNIFIED_END_NAMESPACE
