#ifndef UNIFIED_GRAPHICS_MATH_VERTEX2_HPP
#define UNIFIED_GRAPHICS_MATH_VERTEX2_HPP

#include <unified/graphics/math/vertex_fwd.hpp>

#include <unified/core/math/point2.hpp>
#include <unified/core/color.hpp>

UNIFIED_BEGIN_NAMESPACE

template <class _type>
class Vertex<_type, 2> : public Point<_type, 2>
{
public:

    _UNIFIED_CONSTEXPR Vertex() _UNIFIED_NOEXCEPT : Point<_type, 2>(), color() { }

    _UNIFIED_CONSTEXPR Vertex(Point<_type, 2> const &point) _UNIFIED_NOEXCEPT : color() {
        this->x = point.x, this->y = point.y;
    }

    _UNIFIED_CONSTEXPR Vertex(Point<_type, 2> const &point, Color const &color) _UNIFIED_NOEXCEPT : color(color) {
        this->x = point.x, this->y = point.y;
    }

    _UNIFIED_CONSTEXPR operator Point<_type, 2>() const {
        return Point<_type, 2>(this->x, this->y);
    }

    Color color;

};

typedef Vertex<unsigned, 2> Vertex2u;
typedef Vertex<int,      2> Vertex2i;
typedef Vertex<float,    2> Vertex2f;
typedef Vertex<double,   2> Vertex2d;

UNIFIED_END_NAMESPACE

#endif
