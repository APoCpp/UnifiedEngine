#ifndef UNIFIED_GRAPHICS_MATH_TRANSFORM_HPP
#define UNIFIED_GRAPHICS_MATH_TRANSFORM_HPP

#include <unified/graphics/math/transform_fwd.hpp>
#include <unified/graphics/math/vertex_fwd.hpp>
#include <unified/core/math/matrix.hpp>

UNIFIED_BEGIN_NAMESPACE

template <u32 _dimension>
class Transform<double, _dimension> : public Matrix<double, _dimension, _dimension>
{
public:

    _OSL_CONSTEXPR Transform() _OSL_NOEXCEPT : Matrix<double, _dimension, _dimension>() {
        for (u32 dim = 0; dim < _dimension; dim++) {
            this->_data[dim][dim] = 1.0;
        }
    }

    _OSL_CONSTEXPR Point<double, _dimension - 1> translate(Point<double, _dimension - 1> const &move) _OSL_NOEXCEPT {
        Point<double, _dimension - 1> result;

        for (u32 col = 0; col < this->columns(); col++) {
            for (u32 row = 0; row < this->rows(); row++) {
                if (col < result.size() && row < result.size())
                    result[col] += this->_data[col][row] * move[row];
                else if (col < result.size())
                    result[col] += this->_data[col][row] * 1.0;
            }
        }

        return result;
    }

};

template <u32 _dimension>
class Transform<float, _dimension> : public Matrix<float, _dimension, _dimension>
{
public:

    _OSL_CONSTEXPR Transform() _OSL_NOEXCEPT : Matrix<float, _dimension, _dimension>() {
        for (u32 dim = 0; dim < _dimension; dim++) {
            this->_data[dim][dim] = 1.f;
        }
    }

    _OSL_CONSTEXPR Point<double, _dimension - 1> translate(Point<double, _dimension - 1> const &move) _OSL_NOEXCEPT {
        Point<double, _dimension - 1> result;

        for (u32 col = 0; col < this->columns(); col++) {
            for (u32 row = 0; row < this->rows(); row++) {
                if (col < result.size() && row < result.size())
                    result[col] += this->_data[col][row] * move[row];
                else if (col < result.size())
                    result[col] += this->_data[col][row] * 1.f;
            }
        }

        return result;
    }

};

typedef Transform<double, 4> Transform4d;
typedef Transform<double, 3> Transform3d;
typedef Transform<float,  4> Transform4f;
typedef Transform<float,  3> Transform3f;

UNIFIED_END_NAMESPACE

#endif
