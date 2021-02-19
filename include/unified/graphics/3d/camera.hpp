#ifndef _UNIFIED_GRAPHICS_3D_CAMERA_HPP
#define _UNIFIED_GRAPHICS_3D_CAMERA_HPP

# include <unified/core/math/point3.hpp>
# include <unified/core/math/matrix.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_3D_BEGIN_NAMESPACE

typedef Matrix<double, 4, 4> Projection;

class Camera
{
public:

    Camera(const Point3d &position);
    Camera(const Projection &projection);

    virtual ~Camera() { }

    Point3d get_position() const;
    void set_position(const Point3d &position);

    const Projection &get_projection() const;

protected:

    void recalculate();

    Point3d _position;
    Projection _projection;

};

UNIFIED_GRAPHICS_3D_END_NAMESPACE
UNIFIED_END_NAMESPACE

#endif
