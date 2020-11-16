#ifndef _UNIFIED_APPLICATION_EVENT_WINDOW_CLOSE_HPP
#define _UNIFIED_APPLICATION_EVENT_WINDOW_CLOSE_HPP

# include <unified/application/event/event.hpp>

UNIFIED_BEGIN_NAMESPACE

class WindowCloseEvent : public Event
{
public:

    UNIFIED_NODISCARD virtual string get_name() const;
    UNIFIED_NODISCARD virtual Type get_type() const;

    UNIFIED_NODISCARD static Type get_type_static() {
        return Type::WindowClose;
    }

};

UNIFIED_END_NAMESPACE

#endif
