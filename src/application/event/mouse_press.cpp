#include <unified/application/event/mouse_press.hpp>

UNIFIED_BEGIN_NAMESPACE

MousePressEvent::MousePressEvent(int code, int action) _UNIFIED_NOEXCEPT : code((Mouse::Code)code), action((Mouse::Action)action) { }

_UNIFIED_NODISCARD string MousePressEvent::get_name() const {
    return "MousePressEvent";
}

_UNIFIED_NODISCARD Event::Type MousePressEvent::get_type() const {
    return Type::MousePress;
}

UNIFIED_END_NAMESPACE
