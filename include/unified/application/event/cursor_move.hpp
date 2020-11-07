#ifndef UNIFIED_APPLICATION_EVENT_CURSOR_MOVE_HPP
#define UNIFIED_APPLICATION_EVENT_CURSOR_MOVE_HPP

#include <unified/defines.hpp>
#include <unified/application/event/event.hpp>
#include <unified/core/math/point2.hpp>

UNIFIED_BEGIN_NAMESPACE

class CursorMoveEvent : public Event
{
public:

    CursorMoveEvent(double x, double y) _UNIFIED_NOEXCEPT;

    _UNIFIED_NODISCARD virtual string get_name() const;
    _UNIFIED_NODISCARD virtual Type get_type() const;

    _UNIFIED_NODISCARD static Type get_type_static() {
        return Type::CursorMove;
    }

    const Point2d position;

};

UNIFIED_END_NAMESPACE

#endif
