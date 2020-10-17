#include <unified/core/clock.hpp>
#include <GLFW/glfw3.h>

Unified::Clock::Clock() { restart(); }

Unified::Time Unified::Clock::get_elapsed_time() const _OSL_NOEXCEPT {
    Time sec = seconds(glfwGetTime());
    return sec - _timestamp;
}

Unified::Time Unified::Clock::restart() _OSL_NOEXCEPT {
    _timestamp = seconds(glfwGetTime());
    return _timestamp;
}