#include <unified/application/event/window_resize.hpp>

UNIFIED_BEGIN_NAMESPACE

WindowResizeEvent::WindowResizeEvent(int horizontal, int vertical) _UNIFIED_NOEXCEPT : size(horizontal, vertical) { }

_UNIFIED_NODISCARD string WindowResizeEvent::get_name() const {
    return "WindowResizeEvent";
}

_UNIFIED_NODISCARD Event::Type WindowResizeEvent::get_type() const {
    return Type::WindowResize;
}

UNIFIED_END_NAMESPACE
