#ifndef UNIFIED_APPLICATION_EVENT_WINDOW_MAXIMIZE_HPP
#define UNIFIED_APPLICATION_EVENT_WINDOW_MAXIMIZE_HPP

#include <unified/defines.hpp>
#include <unified/application/event/event.hpp>

UNIFIED_BEGIN_NAMESPACE

class WindowMaximizeEvent : public Event
{
public:

    WindowMaximizeEvent(int maximized) _UNIFIED_NOEXCEPT;

    _UNIFIED_NODISCARD virtual string get_name() const;
    _UNIFIED_NODISCARD virtual Type get_type() const;

    _UNIFIED_NODISCARD static Type get_type_static() {
        return Type::WindowMaximize;
    }

    const bool maximized;

};

UNIFIED_END_NAMESPACE

#endif
