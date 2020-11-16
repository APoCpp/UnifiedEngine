#include <unified/application/event/cursor_move.hpp>

UNIFIED_BEGIN_NAMESPACE

CursorMoveEvent::CursorMoveEvent(double x, double y) : position(x, y) { }

UNIFIED_NODISCARD string CursorMoveEvent::get_name() const {
    return "CursorMoveEvent";
}

UNIFIED_NODISCARD Event::Type CursorMoveEvent::get_type() const {
    return Type::CursorMove;
}

UNIFIED_END_NAMESPACE
