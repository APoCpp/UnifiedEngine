#include <unified/application/event/window_resize.hpp>

UNIFIED_BEGIN_NAMESPACE

WindowResizeEvent::WindowResizeEvent(int horizontal, int vertical) : size(horizontal, vertical) { }

UNIFIED_END_NAMESPACE
