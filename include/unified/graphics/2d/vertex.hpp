#ifndef _UNIFIED_GRAPHICS_2D_VERTEX_HPP
#define _UNIFIED_GRAPHICS_2D_VERTEX_HPP

# include <unified/graphics/vertex_fwd.hpp>
# include <unified/core/math/point2.hpp>
# include <unified/graphics/color.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

template <class _type>
struct Vertex<_type, 2>
{

    UNIFIED_CONSTEXPR Vertex() : point(), color(), texture() { }

    UNIFIED_CONSTEXPR Vertex(const Point<_type, 2> &point) : point(point), color(), texture() { }

    UNIFIED_CONSTEXPR Vertex(const Color &color) : point(), color(color), texture() { }

    UNIFIED_CONSTEXPR Vertex(const Point<_type, 2> &point, const Color &color) : point(point), color(color), texture() { }

    UNIFIED_CONSTEXPR Vertex(const Point<_type, 2> &point, const Point<_type, 2> &vertex) : point(point), color(), texture(vertex) { }

    UNIFIED_CONSTEXPR Vertex(const Point<_type, 2> &point, const Color &color, const Point<_type, 2> &vertex) : point(point), color(color), texture(vertex) { }

    UNIFIED_CONSTEXPR bool operator==(const Vertex &r) const {
        return this->point == r.point && this->color == r.color && this->texture == r.texture;
    }

    UNIFIED_CONSTEXPR bool operator!=(const Vertex &r) const {
        return !this->operator==(r);
    }

    Point<_type, 2> point;
    Color color;
    Point<_type, 2> texture;
    
};

typedef Vertex<unsigned, 2> Vertex2u;
typedef Vertex<int,      2> Vertex2i;
typedef Vertex<float,    2> Vertex2f;
typedef Vertex<double,   2> Vertex2d;

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE

#endif
