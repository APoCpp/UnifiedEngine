#include <unified/application/event/window_move.hpp>

UNIFIED_BEGIN_NAMESPACE

WindowMoveEvent::WindowMoveEvent(int x, int y) _OSL_NOEXCEPT : position(x, y) { }

_OSL_NODISCARD string WindowMoveEvent::get_name() const {
    return "WindowMoveEvent";
}

_OSL_NODISCARD Event::Type WindowMoveEvent::get_type() const {
    return Type::WindowMove;
}

UNIFIED_END_NAMESPACE
