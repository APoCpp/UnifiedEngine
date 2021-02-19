#ifndef _UNIFIED_CORE_MATH_DETAIL_MATRIX_INVERSE_HPP
#define _UNIFIED_CORE_MATH_DETAIL_MATRIX_INVERSE_HPP

# include <unified/core/math/point4.hpp>

# include "determinant.hpp"

UNIFIED_BEGIN_NAMESPACE

template <class _type>
UNIFIED_CONSTEXPR Matrix<_type, 2, 2> inverse(const Matrix<_type, 2, 2> &m) {
    _type determinant = compute_determinant(m);
    return Matrix<_type, 2, 2> {
        { + m[1][1] * determinant, - m[0][1] * determinant },
        { - m[1][0] * determinant, + m[0][0] * determinant }
    };
}

template <class _type>
UNIFIED_CONSTEXPR Matrix<_type, 3, 3> inverse(const Matrix<_type, 3, 3> &m) {
    _type determinant = compute_determinant(m);
    return Matrix<_type, 3, 3> {
        {
            + (m[1][1] * m[2][2] - m[2][1] * m[1][2]) * determinant,
            - (m[0][1] * m[2][2] - m[2][1] * m[0][2]) * determinant,
            + (m[0][1] * m[1][2] - m[1][1] * m[0][2]) * determinant
        },
        {
            - (m[1][0] * m[2][2] - m[2][0] * m[1][2]) * determinant,
            + (m[0][0] * m[2][2] - m[2][0] * m[0][2]) * determinant,
            - (m[0][0] * m[1][2] - m[1][0] * m[0][2]) * determinant
        },
        {
            + (m[1][0] * m[2][1] - m[2][0] * m[1][1]) * determinant,
            - (m[0][0] * m[2][1] - m[2][0] * m[0][1]) * determinant,
            + (m[0][0] * m[1][1] - m[1][0] * m[0][1]) * determinant
        }
    };
}

template <class _type>
UNIFIED_CONSTEXPR Matrix<_type, 4, 4> inverse(const Matrix<_type, 4, 4> &m) {
    _type coef00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
    _type coef02 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
    _type coef03 = m[1][2] * m[2][3] - m[2][2] * m[1][3];

    _type coef04 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
    _type coef06 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
    _type coef07 = m[1][1] * m[2][3] - m[2][1] * m[1][3];

    _type coef08 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
    _type coef10 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
    _type coef11 = m[1][1] * m[2][2] - m[2][1] * m[1][2];

    _type coef12 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
    _type coef14 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
    _type coef15 = m[1][0] * m[2][3] - m[2][0] * m[1][3];

    _type coef16 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
    _type coef18 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
    _type coef19 = m[1][0] * m[2][2] - m[2][0] * m[1][2];

    _type coef20 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
    _type coef22 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
    _type coef23 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

    _type fac0[4] = { coef00, coef00, coef02, coef03 };
    _type fac1[4] = { coef04, coef04, coef06, coef07 };
    _type fac2[4] = { coef08, coef08, coef10, coef11 };
    _type fac3[4] = { coef12, coef12, coef14, coef15 };
    _type fac4[4] = { coef16, coef16, coef18, coef19 };
    _type fac5[4] = { coef20, coef20, coef22, coef23 };

    _type vec0[4] = { m[1][0], m[0][0], m[0][0], m[0][0] };
    _type vec1[4] = { m[1][1], m[0][1], m[0][1], m[0][1] };
    _type vec2[4] = { m[1][2], m[0][2], m[0][2], m[0][2] };
    _type vec3[4] = { m[1][3], m[0][3], m[0][3], m[0][3] };

    _type inv0(vec1 * fac0 - vec2 * fac1 + vec3 * fac2);
    _type inv1(vec0 * fac0 - vec2 * fac3 + vec3 * fac4);
    _type inv2(vec0 * fac1 - vec1 * fac3 + vec3 * fac5);
    _type inv3(vec0 * fac2 - vec1 * fac4 + vec2 * fac5);

    _type sign_1(+1, -1, +1, -1);
    _type sign_2(-1, +1, -1, +1);

    Matrix<_type, 4, 4> inverse(inv0 * sign_1, inv1 * sign_2, inv2 * sign_1, inv3 * sign_2);

    Point<_type, 4> row0[4] = { inverse[0][0], inverse[1][0], inverse[2][0], inverse[3][0] };

    _type dot0[4] = { row0 * m[0] };

    return inverse * (_type(1) / (dot0[0] + dot0[1]) + (dot0[2] + dot0[3]));
}

UNIFIED_END_NAMESPACE

#endif
