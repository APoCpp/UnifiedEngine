#ifndef _UNIFIED_APPLICATION_EVENT_WINDOW_MAXIMIZE_HPP
#define _UNIFIED_APPLICATION_EVENT_WINDOW_MAXIMIZE_HPP

# include <unified/application/event.hpp>

UNIFIED_BEGIN_NAMESPACE

class WindowMaximizeEvent : public Event
{
public:

    WindowMaximizeEvent(int maximized);

    UNIFIED_NODISCARD virtual string get_name() const;
    UNIFIED_NODISCARD virtual Type get_type() const;

    UNIFIED_NODISCARD static Type get_type_static() {
        return Type::WindowMaximize;
    }

    const bool maximized;

};

UNIFIED_END_NAMESPACE

#endif
