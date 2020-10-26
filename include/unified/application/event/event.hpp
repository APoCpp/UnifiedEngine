#ifndef UNIFIED_APPLICATION_EVENT_HPP
#define UNIFIED_APPLICATION_EVENT_HPP

#include <unified/defines.hpp>
#include <unified/core/string.hpp>

UNIFIED_BEGIN_NAMESPACE

class Event
{
public:

    enum class Type
    {
        WindowMaximize,
        WindowResize,
        WindowFocus,
        WindowClose,
        WindowMove,
        CursorMove,
        MousePress,
        KeyPress
    };

    virtual ~Event() = default;

    _OSL_NODISCARD virtual string get_name() const = 0;
    _OSL_NODISCARD virtual Type get_type() const = 0;

};

class EventDispatcher
{
public:

    EventDispatcher(Event &event) _OSL_NOEXCEPT;
    virtual ~EventDispatcher() = default;

    template <class _type, class _function>
    bool dispatch(_function const &callback) const {
        if (_event.get_type() == _type::get_type_static()) {
            callback(static_cast<_type&>(_event));
            return true;
        }
        return false;
    }

    template <class _type>
    _OSL_NODISCARD _type &get_event() const {
        return static_cast<_type&>(_event);
    }

protected:

    Event &_event;

};

UNIFIED_END_NAMESPACE

#endif
