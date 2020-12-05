#include <unified/graphics/drawable/convex_shape.hpp>
#include <unified/graphics/shader.hpp>
#include <glad/glad.h>

UNIFIED_BEGIN_NAMESPACE

ConvexShape::ConvexShape(u32 vertices_dimension, Buffer::Usage usage) :
    VertexArray(PrimitiveType::Polygon, vertices_dimension, 0, usage) { }

ConvexShape::~ConvexShape() { }

UNIFIED_END_NAMESPACE
