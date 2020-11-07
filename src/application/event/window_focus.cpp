#include <unified/application/event/window_focus.hpp>

UNIFIED_BEGIN_NAMESPACE

WindowFocusEvent::WindowFocusEvent(int focused) _UNIFIED_NOEXCEPT : focused(focused) { }

_UNIFIED_NODISCARD string WindowFocusEvent::get_name() const {
    return "WindowFocusEvent";
}

_UNIFIED_NODISCARD Event::Type WindowFocusEvent::get_type() const {
    return Type::WindowFocus;
}

UNIFIED_END_NAMESPACE
