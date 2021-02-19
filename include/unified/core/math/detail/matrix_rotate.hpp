#ifndef _UNIFIED_CORE_MATH_DETAIL_MATRIX_ROTATE_HPP
#define _UNIFIED_CORE_MATH_DETAIL_MATRIX_ROTATE_HPP

# include <unified/core/math/matrix_fwd.hpp>
# include <unified/core/math/point_fwd.hpp>
# include <cmath>

UNIFIED_BEGIN_NAMESPACE

template <class _type>
UNIFIED_CONSTEXPR Matrix<_type, 3, 3> rotate(const Matrix<_type, 3, 3> &m, const _type &angle) {
    const _type a = angle, c = cos(a), s = sin(a);

    Matrix<_type, 3, 3> result;

    result[0][0] = m[0][0] * c + m[0][1] * s;
    result[0][1] = m[0][0] * -s + m[0][1] * c;
    result[0][2] = m[0][2];

    return result;
}

template <class _type>
UNIFIED_CONSTEXPR Matrix<_type, 4, 4> rotate(const Matrix<_type, 4, 4> &m, const _type &angle, Point<_type, 3> const& vector) {
    const _type a = angle, c = cos(a), s = sin(a);

    Point<_type, 3> axis(vector.normalize());
    Point<_type, 3> temp((_type(1) - c) * axis);

    Matrix<_type, 4, 4> rotate;

    rotate[0][0] = c + temp[0] * axis[0];
    rotate[0][1] = temp[0] * axis[1] + s * axis[2];
    rotate[0][2] = temp[0] * axis[2] - s * axis[1];

    rotate[1][0] = temp[1] * axis[0] - s * axis[2];
    rotate[1][1] = c + temp[1] * axis[1];
    rotate[1][2] = temp[1] * axis[2] + s * axis[0];

    rotate[2][0] = temp[2] * axis[0] + s * axis[1];
    rotate[2][1] = temp[2] * axis[1] - s * axis[0];
    rotate[2][2] = c + temp[2] * axis[2];

    auto result = Matrix<_type, 4, 4>();
    for (u32 row = 0; row < result.rows(); row++) {
        for (u32 col = 0; col < result.columns(); col++) {
            if (row == col)
                result[row][col] = _type(1);
        }
    }

    result[0] = m[0] * rotate[0][0] + m[1] * rotate[0][1] + m[2] * rotate[0][2];
    result[1] = m[0] * rotate[1][0] + m[1] * rotate[1][1] + m[2] * rotate[1][2];
    result[2] = m[0] * rotate[2][0] + m[1] * rotate[2][1] + m[2] * rotate[2][2];
    result[3] = m[3];

    return result;
}


UNIFIED_END_NAMESPACE

#endif
