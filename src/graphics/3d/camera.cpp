#include <unified/graphics/3d/camera.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_3D_BEGIN_NAMESPACE

Camera::Camera(const Point3d &position) :
    _projection({ { 1.0, 0.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0, 0.0 }, { 0.0, 0.0, 1.0, 0.0 }, { 0.0, 0.0, 0.0, 1.0 } }) {
    set_position(position);
}

Camera::Camera(const Projection &projection) : _projection(projection) { }

void Camera::set_position(const Point3d &position) {
    _position = position, recalculate();
}

const Projection &Camera::get_projection() const {
    return _projection;
}

void Camera::recalculate() {
    _projection = translate<double, 4, 4>({ _position.x, _position.y, _position.z });
}

UNIFIED_GRAPHICS_3D_END_NAMESPACE
UNIFIED_END_NAMESPACE
