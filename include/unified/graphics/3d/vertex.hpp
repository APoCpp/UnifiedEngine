#ifndef _UNIFIED_GRAPHICS_3D_VERTEX_HPP
#define _UNIFIED_GRAPHICS_3D_VERTEX_HPP

# include <unified/graphics/vertex_fwd.hpp>
# include <unified/core/math/point3.hpp>
# include <unified/graphics/color.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

template <class _type>
struct Vertex<_type, 3> : public Point<_type, 3>
{

    UNIFIED_CONSTEXPR Vertex() : Point<_type, 3>(), color(), texture() { }

    UNIFIED_CONSTEXPR Vertex(const Point<_type, 3> &point) : Point<_type, 3>(point), color(), texture() { }

    UNIFIED_CONSTEXPR Vertex(const Point<_type, 3> &point, const Color &color) : Point<_type, 3>(point), color(color), texture() { }

    UNIFIED_CONSTEXPR Vertex(const Point<_type, 3> &point, const Point<_type, 2> &vertex) : Point<_type, 3>(point), color(), texture(vertex) { }

    UNIFIED_CONSTEXPR Vertex(const Point<_type, 3> &point, const Color &color, const Point<_type, 2> &vertex) : Point<_type, 3>(point), color(color), texture(vertex) { }

    UNIFIED_CONSTEXPR bool operator==(const Vertex &r) const {
        return this->x == r.x && this->y == r.y && this->color == r.color;
    }

    UNIFIED_CONSTEXPR bool operator!=(const Vertex &r) const {
        return !this->operator==(r);
    }

    Color color;
    Point<_type, 2> texture;

};

typedef Vertex<unsigned, 3> Vertex3u;
typedef Vertex<int,      3> Vertex3i;
typedef Vertex<float,    3> Vertex3f;
typedef Vertex<double,   3> Vertex3d;

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE

#endif
