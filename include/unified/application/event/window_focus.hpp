#ifndef _UNIFIED_APPLICATION_EVENT_WINDOW_FOCUS_HPP
#define _UNIFIED_APPLICATION_EVENT_WINDOW_FOCUS_HPP

# include <unified/application/event.hpp>

UNIFIED_BEGIN_NAMESPACE

class WindowFocusEvent : public Event
{
public:

    WindowFocusEvent(int focused);

    UNIFIED_NODISCARD virtual string get_name() const;
    UNIFIED_NODISCARD virtual Type get_type() const;

    UNIFIED_NODISCARD static Type get_type_static() {
        return Type::WindowFocus;
    }

    const bool focused;

};

UNIFIED_END_NAMESPACE

#endif
