#include <unified/graphics/vertex.hpp>

UNIFIED_BEGIN_NAMESPACE

Vertex::Vertex() _OSL_NOEXCEPT : position(0.f, 0.f), color(), tex_coords(0.f, 0.f) { }

Vertex::Vertex(Vector2f const &position) _OSL_NOEXCEPT : position(position), color(), tex_coords(0.f, 0.f) { }

Vertex::Vertex(Vector2f const &position, Color const &color) _OSL_NOEXCEPT : position(position), color(color), tex_coords(0.f, 0.f) { }

Vertex::Vertex(Vector2f const &position, Vector2f const &tex_сoords) _OSL_NOEXCEPT : position(position), color(), tex_coords(tex_сoords) { }

Vertex::Vertex(Vector2f const &position, Color const &color, Vector2f const &tex_coords) _OSL_NOEXCEPT : position(position), color(color), tex_coords(tex_coords) { }

UNIFIED_END_NAMESPACE
