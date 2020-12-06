#ifndef _UNIFIED_APPLICATION_EVENT_KEY_PRESS_HPP
#define _UNIFIED_APPLICATION_EVENT_KEY_PRESS_HPP

# include <unified/application/event.hpp>
# include <unified/core/input/keyboard.hpp>

UNIFIED_BEGIN_NAMESPACE

class KeyPressEvent : public Event
{
public:

    KeyPressEvent(int code, int action);

    UNIFIED_EVENT_CLASS_TYPE(Type::KeyPress)

    const Keyboard::Code code;
    const Keyboard::Action action;

};

UNIFIED_END_NAMESPACE

#endif
