#include <unified/application/event/window_close.hpp>
#include <typeinfo>

Unified::string Unified::WindowCloseEvent::get_name() const {
    return "WindowCloseEvent";
}

Unified::Event::Type Unified::WindowCloseEvent::get_type() const {
    return Type::WindowClose;
}
