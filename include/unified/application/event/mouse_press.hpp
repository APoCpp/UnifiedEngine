#ifndef _UNIFIED_APPLICATION_EVENT_MOUSE_PRESS_HPP
#define _UNIFIED_APPLICATION_EVENT_MOUSE_PRESS_HPP

# include <unified/application/event.hpp>
# include <unified/core/input/mouse.hpp>

UNIFIED_BEGIN_NAMESPACE

class MousePressEvent : public Event
{
public:

    MousePressEvent(int code, int action);

    UNIFIED_EVENT_CLASS_TYPE(Type::MousePress)

    const Mouse::Code code;
    const Mouse::Action action;

};

UNIFIED_END_NAMESPACE

#endif
