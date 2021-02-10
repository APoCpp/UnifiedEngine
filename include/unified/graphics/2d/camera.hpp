#ifndef _UNIFIED_GRAPHICS_2D_CAMERA_HPP
#define _UNIFIED_GRAPHICS_2D_CAMERA_HPP

# include <unified/core/math/matrix.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_2D_BEGIN_NAMESPACE

typedef Matrix<double, 2, 2> Projection;

class Camera
{
public:

    Camera();
    Camera(const Projection &projection);

    virtual ~Camera() { }

    Projection &get_projection();

protected:

    Projection _projection;

};

UNIFIED_GRAPHICS_2D_END_NAMESPACE
UNIFIED_END_NAMESPACE

#endif
