#include <unified/application/event/mouse_press.hpp>

UNIFIED_BEGIN_NAMESPACE

MousePressEvent::MousePressEvent(int code, int action) _OSL_NOEXCEPT : code((Mouse::Code)code), action((Mouse::Action)action) { }

_OSL_NODISCARD string MousePressEvent::get_name() const {
    return "MousePressEvent";
}

_OSL_NODISCARD Event::Type MousePressEvent::get_type() const {
    return Type::MousePress;
}

UNIFIED_END_NAMESPACE
