#ifndef UNIFIED_APPLICATION_EVENT_WINDOW_RESIZE_HPP
#define UNIFIED_APPLICATION_EVENT_WINDOW_RESIZE_HPP

# include <unified/application/event.hpp>
# include <unified/core/math/point2.hpp>

UNIFIED_BEGIN_NAMESPACE

class WindowResizeEvent : public Event
{
public:

    WindowResizeEvent(int horizontal, int vertical);

    UNIFIED_NODISCARD virtual string get_name() const;
    UNIFIED_NODISCARD virtual Type get_type() const;

    UNIFIED_NODISCARD static Type get_type_static() {
        return Type::WindowResize;
    }

    const Point2i size;

};

UNIFIED_END_NAMESPACE

#endif
