#ifndef UNIFIED_GRAPHICS_VERTEX_HPP
#define UNIFIED_GRAPHICS_VERTEX_HPP

#include <unified/defines.hpp>
#include <unified/core/color.hpp>
#include <unified/core/math/vector2.hpp>

UNIFIED_BEGIN_NAMESPACE

class Vertex
{
public:

    Vertex() _OSL_NOEXCEPT;
    Vertex(Vector2f const &position) _OSL_NOEXCEPT;
    Vertex(Vector2f const &position, Color const &color) _OSL_NOEXCEPT;
    Vertex(Vector2f const &position, Vector2f const &tex_сoords) _OSL_NOEXCEPT;
    Vertex(Vector2f const &position, Color const &color, Vector2f const &tex_coords) _OSL_NOEXCEPT;

    virtual ~Vertex() _OSL_NOEXCEPT = default;

    Vector2f position;
    Color color;
    Vector2f tex_coords;

};

UNIFIED_END_NAMESPACE

#endif
