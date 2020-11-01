#include <unified/graphics/vars.hpp>

#include <glad/glad.h>
#include <unified/core/math/matrix.hpp>

UNIFIED_BEGIN_NAMESPACE

_OSL_NODISCARD Matrix<double, 4, 4> get_modelview_matrix() _OSL_NOEXCEPT {
    Matrix4x4d matrix;
    glGetDoublev(GL_MODELVIEW_MATRIX, matrix.data());
    return matrix;
}

UNIFIED_END_NAMESPACE
