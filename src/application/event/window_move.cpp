#include <unified/application/event/window_move.hpp>

UNIFIED_BEGIN_NAMESPACE

WindowMoveEvent::WindowMoveEvent(int x, int y) : position(x, y) { }

UNIFIED_END_NAMESPACE
