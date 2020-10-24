#include <unified/defines.hpp>

#ifndef UNIFIED_APPLICATION_EVENT_HPP
#define UNIFIED_APPLICATION_EVENT_HPP

#include <unified/core/string.hpp>

UNIFIED_BEGIN_NAMESPACE

class Event
{
public:

    enum class Type
    {
        WindowClose
    };

    virtual ~Event() = default;

    virtual string get_name() const = 0;
    virtual Type get_type() const = 0;

};

UNIFIED_END_NAMESPACE

#endif
