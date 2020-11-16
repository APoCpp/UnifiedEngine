#ifndef _UNIFIED_APPLICATION_EVENT_HPP
#define _UNIFIED_APPLICATION_EVENT_HPP

# include <unified/core/string.hpp>

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

    UNIFIED_NODISCARD virtual string get_name() const = 0;
    UNIFIED_NODISCARD virtual Type get_type() const = 0;

};

class EventDispatcher
{
public:

    EventDispatcher(Event &event);
    virtual ~EventDispatcher() = default;

    template <class _type, class _function>
    bool dispatch(const _function &callback) const {
        if (_event.get_type() == _type::get_type_static()) {
            callback(static_cast<_type&>(_event));
            return true;
        }
        return false;
    }

    template <class _type>
    UNIFIED_NODISCARD _type &get_event() const {
        return static_cast<_type&>(_event);
    }

protected:

    Event &_event;

};

UNIFIED_END_NAMESPACE

#endif
