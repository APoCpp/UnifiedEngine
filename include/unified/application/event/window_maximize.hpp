#ifndef UNIFIED_APPLICATION_EVENT_WINDOW_MAXIMIZE_HPP
#define UNIFIED_APPLICATION_EVENT_WINDOW_MAXIMIZE_HPP

#include <unified/defines.hpp>
#include <unified/application/event/event.hpp>

UNIFIED_BEGIN_NAMESPACE

class WindowMaximizeEvent : public Event
{
public:

    WindowMaximizeEvent(int maximized) _OSL_NOEXCEPT;

    _OSL_NODISCARD virtual string get_name() const;
    _OSL_NODISCARD virtual Type get_type() const;

    _OSL_NODISCARD static Type get_type_static() {
        return Type::WindowMaximize;
    }

    const bool maximized;

};

UNIFIED_END_NAMESPACE

#endif
