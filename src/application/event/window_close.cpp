#include <unified/application/event/window_close.hpp>

UNIFIED_BEGIN_NAMESPACE

UNIFIED_NODISCARD string WindowCloseEvent::get_name() const {
    return "WindowCloseEvent";
}

UNIFIED_NODISCARD Event::Type WindowCloseEvent::get_type() const {
    return Type::WindowClose;
}

UNIFIED_END_NAMESPACE
