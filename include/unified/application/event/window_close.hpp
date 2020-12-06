#ifndef _UNIFIED_APPLICATION_EVENT_WINDOW_CLOSE_HPP
#define _UNIFIED_APPLICATION_EVENT_WINDOW_CLOSE_HPP

# include <unified/application/event.hpp>

UNIFIED_BEGIN_NAMESPACE

class WindowCloseEvent : public Event
{
public:

    UNIFIED_EVENT_CLASS_TYPE(Type::WindowClose)

};

UNIFIED_END_NAMESPACE

#endif
