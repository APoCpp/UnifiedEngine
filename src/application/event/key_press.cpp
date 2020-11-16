#include <unified/application/event/key_press.hpp>

UNIFIED_BEGIN_NAMESPACE

KeyPressEvent::KeyPressEvent(int code, int action) : code((Keyboard::Code)code), action((Keyboard::Action)action) { }

UNIFIED_NODISCARD string KeyPressEvent::get_name() const {
    return "KeyPressEvent";
}

UNIFIED_NODISCARD Event::Type KeyPressEvent::get_type() const {
    return Type::KeyPress;
}

UNIFIED_END_NAMESPACE
