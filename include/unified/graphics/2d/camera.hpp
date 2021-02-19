#ifndef _UNIFIED_GRAPHICS_2D_CAMERA_HPP
#define _UNIFIED_GRAPHICS_2D_CAMERA_HPP

# include <unified/core/math/point2.hpp>
# include <unified/core/math/matrix.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_2D_BEGIN_NAMESPACE

typedef Matrix<double, 3, 3> Projection;

class Camera
{
public:

    Camera(const Point2d &position);
    Camera(const Projection &projection);

    virtual ~Camera() { }

    Point2d get_position() const;
    void set_position(const Point2d &position);

    const Projection &get_projection() const;

protected:

    void recalculate();

    Point2d _position, _scale;
    Projection _projection;

};

UNIFIED_GRAPHICS_2D_END_NAMESPACE
UNIFIED_END_NAMESPACE

#endif
