#ifndef _UNIFIED_GRAPHICS_CAMERA_HPP
#define _UNIFIED_GRAPHICS_CAMERA_HPP

# include <unified/core/math/matrix.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

class Camera
{
public:

	Camera();

	Camera(const Matrix4x4d &projection);

	virtual ~Camera() { }

	const Matrix4x4d &get_projection() const;

protected:

	Matrix4x4d _projection;

};

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE

#endif