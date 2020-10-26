#include <unified/application/event/event.hpp>

UNIFIED_BEGIN_NAMESPACE

EventDispatcher::EventDispatcher(Event &event) _OSL_NOEXCEPT : _event(event) { }

UNIFIED_END_NAMESPACE
