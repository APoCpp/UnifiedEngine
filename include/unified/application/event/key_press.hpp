#ifndef UNIFIED_APPLICATION_EVENT_KEY_PRESS_HPP
#define UNIFIED_APPLICATION_EVENT_KEY_PRESS_HPP

#include <unified/defines.hpp>
#include <unified/application/event/event.hpp>
#include <unified/core/input/keyboard.hpp>

UNIFIED_BEGIN_NAMESPACE

class KeyPressEvent : public Event
{
public:

    KeyPressEvent(int code, int action) _UNIFIED_NOEXCEPT;

    _UNIFIED_NODISCARD virtual string get_name() const;
    _UNIFIED_NODISCARD virtual Type get_type() const;

    _UNIFIED_NODISCARD static Type get_type_static() {
        return Type::KeyPress;
    }

    const Keyboard::Code code;
    const Keyboard::Action action;

};

UNIFIED_END_NAMESPACE

#endif
