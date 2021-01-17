#include <unified/graphics/camera.hpp>

#include <glad/glad.h>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

Camera::Camera() {
	glGetDoublev(GL_PROJECTION_MATRIX, _projection.data());
}

Camera::Camera(const Matrix4x4d &projection) : _projection(projection) { }

const Matrix4x4d &Camera::get_projection() const { 
	return _projection; 
}

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE