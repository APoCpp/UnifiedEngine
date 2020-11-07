#ifndef UNIFIED_APPLICATION_EVENT_WINDOW_CLOSE_HPP
#define UNIFIED_APPLICATION_EVENT_WINDOW_CLOSE_HPP

#include <unified/defines.hpp>
#include <unified/application/event/event.hpp>

UNIFIED_BEGIN_NAMESPACE

class WindowCloseEvent : public Event
{
public:

    _UNIFIED_NODISCARD virtual string get_name() const;
    _UNIFIED_NODISCARD virtual Type get_type() const;

    _UNIFIED_NODISCARD static Type get_type_static() {
        return Type::WindowClose;
    }

};

UNIFIED_END_NAMESPACE

#endif
