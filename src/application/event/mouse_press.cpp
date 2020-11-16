#include <unified/application/event/mouse_press.hpp>

UNIFIED_BEGIN_NAMESPACE

MousePressEvent::MousePressEvent(int code, int action) : code((Mouse::Code)code), action((Mouse::Action)action) { }

UNIFIED_NODISCARD string MousePressEvent::get_name() const {
    return "MousePressEvent";
}

UNIFIED_NODISCARD Event::Type MousePressEvent::get_type() const {
    return Type::MousePress;
}

UNIFIED_END_NAMESPACE
