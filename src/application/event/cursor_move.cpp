#include <unified/application/event/cursor_move.hpp>

UNIFIED_BEGIN_NAMESPACE

CursorMoveEvent::CursorMoveEvent(double x, double y) : position(x, y) { }

UNIFIED_END_NAMESPACE
