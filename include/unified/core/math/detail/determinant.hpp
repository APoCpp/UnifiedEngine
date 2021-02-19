#ifndef _UNIFIED_CORE_MATH_DETAIL_DETERMINANT_HPP
#define _UNIFIED_CORE_MATH_DETAIL_DETERMINANT_HPP

# include <unified/core/math/matrix_fwd.hpp>

UNIFIED_BEGIN_NAMESPACE

template <class _type>
UNIFIED_CONSTEXPR _type compute_determinant(const Matrix<_type, 2, 2> &m) {
    return m[0][0] * m[1][1] - m[1][0] * m[0][1];
}

template <class _type>
UNIFIED_CONSTEXPR _type compute_determinant(const Matrix<_type, 3, 3> &m) {
    return
        + m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])
        - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2])
        + m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
}

template <class _type>
UNIFIED_CONSTEXPR _type compute_determinant(const Matrix<_type, 4, 4> &m) {
    _type sub_factor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
    _type sub_factor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
    _type sub_factor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
    _type sub_factor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
    _type sub_factor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
    _type sub_factor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];

    _type det_cof[4] = {
        + (m[1][1] * sub_factor00 - m[1][2] * sub_factor01 + m[1][3] * sub_factor02),
        - (m[1][0] * sub_factor00 - m[1][2] * sub_factor03 + m[1][3] * sub_factor04),
        + (m[1][0] * sub_factor01 - m[1][1] * sub_factor03 + m[1][3] * sub_factor05),
        - (m[1][0] * sub_factor02 - m[1][1] * sub_factor04 + m[1][2] * sub_factor05)
    };

    return
        m[0][0] * det_cof[0] + m[0][1] * det_cof[1] +
        m[0][2] * det_cof[2] + m[0][3] * det_cof[3];
}

UNIFIED_END_NAMESPACE

#endif
