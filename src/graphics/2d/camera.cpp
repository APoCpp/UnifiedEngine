#include <unified/graphics/2d/camera.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_2D_BEGIN_NAMESPACE

Camera::Camera(const Point2d &position) :
    _projection({ { 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { 0.0, 0.0, 1.0 } }) {
    set_position(position);
}

Camera::Camera(const Projection &projection) : _projection(projection) { }

Point2d Camera::get_position() const {
    return _position;
}

void Camera::set_position(const Point2d &position) {
    _position = position, recalculate();
}

const Projection &Camera::get_projection() const {
    return _projection;
}

void Camera::recalculate() {
    _projection = inverse(translate<double, 3, 3>(_position));
}

UNIFIED_GRAPHICS_2D_END_NAMESPACE
UNIFIED_END_NAMESPACE
