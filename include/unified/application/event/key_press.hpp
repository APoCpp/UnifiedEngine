#include <unified/defines.hpp>

#ifndef UNIFIED_APPLICATION_EVENT_KEY_PRESS_HPP
#define UNIFIED_APPLICATION_EVENT_KEY_PRESS_HPP

#include <unified/application/event/event.hpp>
#include <unified/core/input/keyboard.hpp>

UNIFIED_BEGIN_NAMESPACE

class KeyPressEvent : public Event
{
public:

    explicit KeyPressEvent(int ikey, int iaction);

    virtual string get_name() const;
    virtual Type get_type() const;

    static Type get_type_static() {
        return Type::KeyPress;
    }

    const Keyboard::Code key;
    const Keyboard::Action action;

};

UNIFIED_END_NAMESPACE

#endif
