#ifndef UNIFIED_CORE_MATH_MATRIX_HPP
#define UNIFIED_CORE_MATH_MATRIX_HPP

#include <unified/core/math/matrix_fwd.hpp>
#include <unified/core/math/point_fwd.hpp>

#include <initializer_list>
#include <memory>

UNIFIED_BEGIN_NAMESPACE

template <class _type, u32 _rows, u32 _columns>
class Matrix
{
public:

    _UNIFIED_CONSTEXPR Matrix() _UNIFIED_NOEXCEPT {
        std::fill(&_data[0][0], &_data[_rows][0], _type());
    }

    _UNIFIED_CONSTEXPR Matrix(std::initializer_list<std::initializer_list<_type>> matrix) _UNIFIED_NOEXCEPT {
        u32 i = 0;
        for (auto &r : matrix) {
            std::copy(r.begin(), r.end(), _data[i++]);
        }
    }

    _UNIFIED_CONSTEXPR Matrix(_type const &fill) _UNIFIED_NOEXCEPT {
        std::fill(&_data[0][0], &_data[_rows][0], fill);
    }

    _UNIFIED_CONSTEXPR _type operator()(u32 row, u32 column) const _UNIFIED_NOEXCEPT {
        return _data[row][column];
    }

    _UNIFIED_CONSTEXPR _type &operator()(u32 row, u32 column) _UNIFIED_NOEXCEPT {
        return _data[row][column];
    }

    _UNIFIED_CONSTEXPR u32 rows() const _UNIFIED_NOEXCEPT {
        return _rows;
    }

    _UNIFIED_CONSTEXPR u32 columns() const _UNIFIED_NOEXCEPT {
        return _columns;
    }

    _UNIFIED_CONSTEXPR u32 size() const _UNIFIED_NOEXCEPT {
        return _rows * _columns;
    }

    _type const *data() const {
        return reinterpret_cast<_type const*>(_data);
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

template <class _type, uint32_t _rows, uint32_t _columns>
_UNIFIED_CONSTEXPR Point<_type, _columns> operator*(Matrix<_type, _rows, _columns> const &l, Point<_type, _columns> const &r) _UNIFIED_NOEXCEPT {
    Point<_type, _columns> result;
    for (u32 col = 0; col < l.columns(); col++) {
        for (u32 row = 0; row < l.rows(); row++) {
            result[col] += l(col, row) * r[row];
        }
    }
    return result;
}

template <class _type, uint32_t _rows, uint32_t _columns>
_UNIFIED_CONSTEXPR Matrix<_type, _rows, _columns> operator*(Matrix<_type, _rows, _columns> l, Matrix<_type, _rows, _columns> const &r) _UNIFIED_NOEXCEPT {
    for (u32 col = 0; col < l.columns(); col++) {
        for (u32 row = 0; row < l.rows(); row++) {
            l(col, row) *= r(col, row);
        }
    }
    return l;
}

UNIFIED_END_NAMESPACE

#endif
