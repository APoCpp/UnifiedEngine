#include <unified/application/event/window_close.hpp>

UNIFIED_BEGIN_NAMESPACE

string WindowCloseEvent::get_name() const {
    return "WindowCloseEvent";
}

Event::Type WindowCloseEvent::get_type() const {
    return Type::WindowClose;
}

UNIFIED_END_NAMESPACE
