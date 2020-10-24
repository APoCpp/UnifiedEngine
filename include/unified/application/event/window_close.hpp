#include <unified/defines.hpp>

#ifndef UNIFIED_APPLICATION_EVENT_WINDOW_CLOSE_HPP
#define UNIFIED_APPLICATION_EVENT_WINDOW_CLOSE_HPP

#include <unified/application/event/event.hpp>

UNIFIED_BEGIN_NAMESPACE

class WindowCloseEvent : public Event
{
public:

    virtual string get_name() const;
    virtual Type get_type() const;

};

UNIFIED_END_NAMESPACE

#endif
