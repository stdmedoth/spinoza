#ifndef SCALARFIELD_H
#define SCALARFIELD_H

#include <array>
#include <cmath>

#include "Field.hpp"
#include "ScalarFunction.hpp"

template <typename T, std::size_t M, std::size_t N>
class ScalarField : public ScalarFunction<T, M, N>
{

protected:
public:
    ScalarField()
    {
        this->domain = VectorSpace<T, M, N>();
        this->image = Field<T, N>();
    }

    ScalarField(const VectorSpace<T, M, N> &domain, const Field<T, N> &image)
    {
        this->domain = domain;
        this->image = image;
    }

    ScalarField<T, M, N> derivative()
    {
        Field<T, N> result_image{};

        for (std::size_t m = 0; m < M; m++)
        {
            result_image[m + 1] = (this->image[m + 1] - this->image[m]) / (this->domain[m + 1].magnitude() - this->domain[m].magnitude());
        }

        return ScalarField<T, M, N>(this->domain, result_image);
    }

    ScalarField<T, M, N> integral(std::size_t a, std::size_t b)
    {
        Field<T, N> result_image{};

        for (std::size_t i = a; i < b; i++)
        {
            T dx = (this->domain[i + 1] - this->domain[i]).magnitude();
            T avg_value = (this->image[i] + this->image[i + 1]) / 2; // Average (Trapezoid Rule)

            result_image[i + 1] = result_image[i] + avg_value * dx;
        }

        return ScalarField<T, M, N>(this->domain, result_image);
    }

    T &operator[](std::size_t index)
    {
        return this->image[index];
    }
};

#endif
