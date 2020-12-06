#ifndef _UNIFIED_APPLICATION_EVENT_CURSOR_MOVE_HPP
#define _UNIFIED_APPLICATION_EVENT_CURSOR_MOVE_HPP

# include <unified/application/event.hpp>
# include <unified/core/math/point2.hpp>

UNIFIED_BEGIN_NAMESPACE

class CursorMoveEvent : public Event
{
public:

    CursorMoveEvent(double x, double y);

    UNIFIED_EVENT_CLASS_TYPE(Type::CursorMove)

    const Point2d position;

};

UNIFIED_END_NAMESPACE

#endif
