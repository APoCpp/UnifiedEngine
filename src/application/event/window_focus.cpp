#include <unified/application/event/window_focus.hpp>

UNIFIED_BEGIN_NAMESPACE

WindowFocusEvent::WindowFocusEvent(int focused) _OSL_NOEXCEPT : focused(focused) { }

_OSL_NODISCARD string WindowFocusEvent::get_name() const {
    return "WindowFocusEvent";
}

_OSL_NODISCARD Event::Type WindowFocusEvent::get_type() const {
    return Type::WindowFocus;
}

UNIFIED_END_NAMESPACE
