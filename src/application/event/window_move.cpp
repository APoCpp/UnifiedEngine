#include <unified/application/event/window_move.hpp>

UNIFIED_BEGIN_NAMESPACE

WindowMoveEvent::WindowMoveEvent(int x, int y) : position(x, y) { }

UNIFIED_NODISCARD string WindowMoveEvent::get_name() const {
    return "WindowMoveEvent";
}

UNIFIED_NODISCARD Event::Type WindowMoveEvent::get_type() const {
    return Type::WindowMove;
}

UNIFIED_END_NAMESPACE
