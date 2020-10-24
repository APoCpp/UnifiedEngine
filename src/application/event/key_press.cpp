#include <unified/application/event/key_press.hpp>

UNIFIED_BEGIN_NAMESPACE

KeyPressEvent::KeyPressEvent(int key, int action) : key((Keyboard::Code)key), action((Keyboard::Action)action) { }

string KeyPressEvent::get_name() const {
    return "KeyPressEvent";
}

Event::Type KeyPressEvent::get_type() const {
    return Type::KeyPress;
}

UNIFIED_END_NAMESPACE
