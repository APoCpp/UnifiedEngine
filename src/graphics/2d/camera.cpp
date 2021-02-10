#include <unified/graphics/2d/camera.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_2D_BEGIN_NAMESPACE

Camera::Camera() :
    _projection({ { 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { 0.0, 0.0, 1.0 } }) { }

Camera::Camera(const Projection &projection) : _projection(projection) { }

Projection &Camera::get_projection() {
    return _projection;
}

UNIFIED_GRAPHICS_2D_END_NAMESPACE
UNIFIED_END_NAMESPACE
