#ifndef _UNIFIED_APPLICATION_LAYER_HPP
#define _UNIFIED_APPLICATION_LAYER_HPP

# include <unified/defines.hpp>
# include <unified/core/time.hpp>

# include <utility>

UNIFIED_BEGIN_NAMESPACE

class Application;
class EventDispatcher;

class Layer
{
protected:

    friend class Application;

    virtual ~Layer() { }

    virtual void OnPreUpdate() { };
    virtual void OnUpdate(Time) = 0;
    virtual void OnPostUpdate() { };

    virtual void OnEvent(EventDispatcher&) { }

};

UNIFIED_END_NAMESPACE

#endif
