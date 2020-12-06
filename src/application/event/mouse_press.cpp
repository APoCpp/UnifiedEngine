#include <unified/application/event/mouse_press.hpp>

UNIFIED_BEGIN_NAMESPACE

MousePressEvent::MousePressEvent(int code, int action) : code((Mouse::Code)code), action((Mouse::Action)action) { }

UNIFIED_END_NAMESPACE
