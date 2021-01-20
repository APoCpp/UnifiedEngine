#include <unified/graphics/3d/camera.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_3D_BEGIN_NAMESPACE

Camera::Camera() :
    _projection({ { 1.0, 0.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0, 0.0 }, { 0.0, 0.0, 1.0, 0.0 }, { 0.0, 0.0, 0.0, 1.0 } }) { }

Camera::Camera(const Projection &projection) : _projection(projection) { }

const Projection &Camera::get_projection() const {
    return _projection;
}

UNIFIED_GRAPHICS_3D_END_NAMESPACE
UNIFIED_END_NAMESPACE
