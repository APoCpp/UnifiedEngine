#include <unified/application/event/key_press.hpp>

UNIFIED_BEGIN_NAMESPACE

KeyPressEvent::KeyPressEvent(int code, int action) : code((Keyboard::Code)code), action((Keyboard::Action)action) { }

UNIFIED_END_NAMESPACE
