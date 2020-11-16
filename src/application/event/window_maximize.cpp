#include <unified/application/event/window_maximize.hpp>

UNIFIED_BEGIN_NAMESPACE

WindowMaximizeEvent::WindowMaximizeEvent(int maximized) : maximized(maximized) { }

UNIFIED_NODISCARD string WindowMaximizeEvent::get_name() const {
    return "WindowMaximizeEvent";
}

UNIFIED_NODISCARD Event::Type WindowMaximizeEvent::get_type() const {
    return Type::WindowMaximize;
}

UNIFIED_END_NAMESPACE
