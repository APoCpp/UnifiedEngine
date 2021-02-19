#ifndef _UNIFIED_CORE_MATH_MATRIX_HPP
#define _UNIFIED_CORE_MATH_MATRIX_HPP

# include <unified/core/math/matrix_fwd.hpp>
# include <unified/core/math/point_fwd.hpp>

# include <fmt/format.h>

# include "detail/matrix_inverse.hpp"
# include "detail/matrix_rotate.hpp"

# include <initializer_list>
# include <memory>

UNIFIED_BEGIN_NAMESPACE

template <class _type, u32 _rows, u32 _columns>
struct Matrix
{
public:

    UNIFIED_CONSTEXPR Matrix() {
        if UNIFIED_CONSTEXPR (_rows == _columns) {
            for (u32 row = 0; row < _rows; row++)
                for (u32 col = 0; col < _columns; col++)
                    if (row == col) _data[row][col] = _type(1);
                    else _data[row][col] = _type(0);
        } else std::fill(&_data[0][0], &_data[_rows][0], _type(0));
    }

    UNIFIED_CONSTEXPR Matrix(const _type &fill)  {
        if UNIFIED_CONSTEXPR (_rows == _columns) {
            for (u32 row = 0; row < _rows; row++)
                for (u32 col = 0; col < _columns; col++)
                    if (row == col) _data[row][col] = fill;
        } else std::fill(&_data[0][0], &_data[_rows][0], fill);
    }

    UNIFIED_CONSTEXPR Matrix(std::initializer_list<std::initializer_list<_type>> matrix) {
        u32 i = 0;
        for (auto &r : matrix)
            std::copy(r.begin(), r.end(), _data[i++]);
    }

    UNIFIED_CONSTEXPR const _type *operator[](u32 row) const {
        return _data[row];
    }

    UNIFIED_CONSTEXPR _type *operator[](u32 row) {
        return _data[row];
    }

    UNIFIED_FORCE_INLINE u32 rows() const {
        return _rows;
    }

    UNIFIED_FORCE_INLINE u32 columns() const {
        return _columns;
    }

    UNIFIED_CONSTEXPR u32 size() const {
        return _rows * _columns;
    }

    UNIFIED_FORCE_INLINE const _type *data() const {
        return reinterpret_cast<_type const*>(_data);
    }

    UNIFIED_FORCE_INLINE _type *data() {
        return reinterpret_cast<_type*>(_data);
    }

protected:

    _type _data[_rows][_columns];

};

typedef Matrix<unsigned, 3, 3> Matrix3x3u;
typedef Matrix<int,      3, 3> Matrix3x3i;
typedef Matrix<float,    3, 3> Matrix3x3f;
typedef Matrix<double,   3, 3> Matrix3x3d;

typedef Matrix<unsigned, 4, 4> Matrix4x4u;
typedef Matrix<int,      4, 4> Matrix4x4i;
typedef Matrix<float,    4, 4> Matrix4x4f;
typedef Matrix<double,   4, 4> Matrix4x4d;

template <class _type, u32 _rows, u32 _columns>
UNIFIED_CONSTEXPR Matrix<_type, _rows, _columns> translate(const Point<_type, _rows - 1> &direction) {
    auto result = Matrix<_type, _rows, _columns>();

    for (u32 row = 0; row < result.rows(); row++)
        for (u32 col = 0; col < result.columns(); col++)
            if (row == col) result[row][col] = _type(1);

    UNIFIED_CONSTEXPR u32 column_index = _columns - 1;
    for (u32 row = 0; row < direction.size(); row++)
        result[row][column_index] = direction[row];

    return result;
}

template <class _type, u32 _rows, u32 _columns>
UNIFIED_CONSTEXPR Matrix<_type, _rows, _columns> scale(const Point<_type, _rows - 1> &direction) {
    auto result = Matrix<_type, _rows, _columns>();

    for (u32 row = 0; row < (_rows - 1); row++)
        for (u32 col = 0; col < (_columns - 1); col++)
            if (row == col) result[row][col] = _type(2);

    result[_rows - 1][_columns - 1] = _type(1);

    UNIFIED_CONSTEXPR u32 column_index = _columns - 1;
    for (u32 row = 0; row < direction.size(); row++)
        result[row][column_index] = direction[row];

    return result;
}

template <class _type, u32 _rows_1, u32 _columns>
UNIFIED_CONSTEXPR Matrix<_type, _rows_1, _columns> operator*(Matrix<_type, _rows_1, _columns> l, const _type &r) {
    for (u32 row = 0; row < l.rows(); row++)
        for (u32 col = 0; col < l.columns(); col++)
            l[row][col] *= r;

    return l;
}

template <class _type, u32 _rows_1, u32 _rows_2>
UNIFIED_CONSTEXPR Matrix<_type, _rows_1, _rows_2> operator*=(Matrix<_type, _rows_1, _rows_2> &l, const _type &r) {
    return (l = l * r);
}

template <class _type, u32 _rows_1, u32 _columns>
UNIFIED_CONSTEXPR Point<_type, _columns> operator*(const Matrix<_type, _rows_1, _columns> &l, const Point<_type, _columns> &r) {
    Point<_type, _columns> result;

    for (u32 row = 0; row < l.rows(); row++)
        for (u32 col = 0; col < l.columns(); col++)
            result[row] += r[col] * l[row][col];

    return result;
}

template <class _type, u32 _rows_1, u32 _columns>
UNIFIED_CONSTEXPR Point<_type, _columns> operator*=(Matrix<_type, _rows_1, _columns> &l, const Point<_type, _columns> &r) {
    return (l = l * r);
}

template <class _type, u32 _rows_1, u32 _rows_2, u32 _columns>
UNIFIED_CONSTEXPR Matrix<_type, _rows_1, _rows_2> operator*(const Matrix<_type, _rows_1, _rows_2> &l, const Matrix<_type, _rows_2, _columns> &r) {
    Matrix<_type, _rows_1, _rows_2> result;

    for (u32 row = 0; row < l.rows(); row++)
        for (u32 col2 = 0; col2 < r.columns(); col2++)
            for (u32 col = 0; col < l.columns(); col++)
                result[row][col2] += l[row][col] * r[col][col2];

    return result;
}

template <class _type, u32 _rows_1, u32 _rows_2, u32 _columns>
UNIFIED_CONSTEXPR Matrix<_type, _rows_1, _rows_2> operator*=(Matrix<_type, _rows_1, _rows_2> &l, const Matrix<_type, _rows_2, _columns> &r) {
    return (l = l * r);
}

UNIFIED_END_NAMESPACE

#endif
