#ifndef _UNIFIED_APPLICATION_LAYER_HPP
#define _UNIFIED_APPLICATION_LAYER_HPP

# include <unified/defines.hpp>
# include <unified/core/time.hpp>

UNIFIED_BEGIN_NAMESPACE

class Application;
class EventDispatcher;

class Layer
{
public:

    Application *application;

    Layer *set_application_context(Application*);

    virtual ~Layer() { }

    virtual void OnUpdate(Time) = 0;

    virtual void OnEvent(EventDispatcher&) { }

};

UNIFIED_END_NAMESPACE

#endif
