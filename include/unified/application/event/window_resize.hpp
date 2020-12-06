#ifndef _UNIFIED_APPLICATION_EVENT_WINDOW_RESIZE_HPP
#define _UNIFIED_APPLICATION_EVENT_WINDOW_RESIZE_HPP

# include <unified/application/event.hpp>
# include <unified/core/math/point2.hpp>

UNIFIED_BEGIN_NAMESPACE

class WindowResizeEvent : public Event
{
public:

    WindowResizeEvent(int horizontal, int vertical);

    UNIFIED_EVENT_CLASS_TYPE(Type::WindowResize)

    const Point2i size;

};

UNIFIED_END_NAMESPACE

#endif
