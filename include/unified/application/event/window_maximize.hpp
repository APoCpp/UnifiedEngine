#ifndef _UNIFIED_APPLICATION_EVENT_WINDOW_MAXIMIZE_HPP
#define _UNIFIED_APPLICATION_EVENT_WINDOW_MAXIMIZE_HPP

# include <unified/application/event.hpp>

UNIFIED_BEGIN_NAMESPACE

class WindowMaximizeEvent : public Event
{
public:

    WindowMaximizeEvent(int maximized);

    UNIFIED_EVENT_CLASS_TYPE(Type::WindowMaximize)

    const bool maximized;

};

UNIFIED_END_NAMESPACE

#endif
