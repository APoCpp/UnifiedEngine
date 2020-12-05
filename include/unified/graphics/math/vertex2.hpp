#ifndef _UNIFIED_GRAPHICS_VERTEX2_HPP
#define _UNIFIED_GRAPHICS_VERTEX2_HPP

# include <unified/graphics/math/vertex_fwd.hpp>
# include <unified/core/math/point2.hpp>
# include <unified/graphics/color.hpp>

UNIFIED_BEGIN_NAMESPACE

template <class _type>
struct Vertex<_type, 2> : public Point<_type, 2>
{

    UNIFIED_CONSTEXPR Vertex() : Point<_type, 2>(), color() { }

    UNIFIED_CONSTEXPR Vertex(const Point<_type, 2> &point) : color() {
        this->x = point.x, this->y = point.y;
    }

    UNIFIED_CONSTEXPR Vertex(const Point<_type, 2> &point, const Color &color) : color(color) {
        this->x = point.x, this->y = point.y;
    }

    Color color;

};

UNIFIED_END_NAMESPACE

#endif
