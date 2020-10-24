#include <unified/application/event/window_maximize.hpp>

UNIFIED_BEGIN_NAMESPACE

WindowMaximizeEvent::WindowMaximizeEvent(int maximized) _OSL_NOEXCEPT : maximized(maximized) { }

_OSL_NODISCARD string WindowMaximizeEvent::get_name() const {
    return "WindowMaximizeEvent";
}

_OSL_NODISCARD Event::Type WindowMaximizeEvent::get_type() const {
    return Type::WindowMaximize;
}

UNIFIED_END_NAMESPACE
