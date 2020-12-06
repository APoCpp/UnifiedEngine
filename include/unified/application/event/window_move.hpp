#ifndef _UNIFIED_APPLICATION_EVENT_WINDOW_MOVE_HPP
#define _UNIFIED_APPLICATION_EVENT_WINDOW_MOVE_HPP

# include <unified/application/event.hpp>
# include <unified/core/math/point2.hpp>

UNIFIED_BEGIN_NAMESPACE

class WindowMoveEvent : public Event
{
public:

    WindowMoveEvent(int x, int y);

    UNIFIED_EVENT_CLASS_TYPE(Type::WindowMove)

    const Point2i position;

};

UNIFIED_END_NAMESPACE

#endif
