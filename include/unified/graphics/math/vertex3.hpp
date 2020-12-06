#ifndef _UNIFIED_GRAPHICS_VERTEX3_HPP
#define _UNIFIED_GRAPHICS_VERTEX3_HPP

# include <unified/graphics/math/vertex_fwd.hpp>
# include <unified/core/math/point3.hpp>
# include <unified/graphics/color.hpp>

UNIFIED_BEGIN_NAMESPACE

template <class _type>
struct Vertex<_type, 3> : public Point<_type, 3>
{

    UNIFIED_CONSTEXPR Vertex() : Point<_type, 3>(), color() { }

    UNIFIED_CONSTEXPR Vertex(const Point<_type, 3> &point) : color() {
        this->x = point.x, this->y = point.y;
    }

    UNIFIED_CONSTEXPR Vertex(const Point<_type, 3> &point, const Color &color) : color(color) {
        this->x = point.x, this->y = point.y;
    }

    Color color;

};

UNIFIED_END_NAMESPACE

#endif
