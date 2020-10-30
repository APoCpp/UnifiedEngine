#ifndef UNIFIED_APPLICATION_EVENT_WINDOW_MOVE_HPP
#define UNIFIED_APPLICATION_EVENT_WINDOW_MOVE_HPP

#include <unified/defines.hpp>
#include <unified/application/event/event.hpp>
#include <unified/core/math/point2.hpp>

UNIFIED_BEGIN_NAMESPACE

class WindowMoveEvent : public Event
{
public:

    WindowMoveEvent(int x, int y) _OSL_NOEXCEPT;

    _OSL_NODISCARD virtual string get_name() const;
    _OSL_NODISCARD virtual Type get_type() const;

    _OSL_NODISCARD static Type get_type_static() {
        return Type::WindowMove;
    }

    const Point2i position;

};

UNIFIED_END_NAMESPACE

#endif
