#ifndef SCALARFIELD_HPP
#define SCALARFIELD_HPP

#include <array>
#include <cmath>

#include "ScalarFunction.hpp"
#include "Space.hpp"

template <typename T, std::size_t M, std::size_t N>
class ScalarField : public ScalarFunction<T, M, N>
{

protected:
public:
    ScalarField()
    {
        this->domain = Space<T, M, N>();
        this->image = Space<T, 1, N>();
    }

    ScalarField(const Space<T, M, N> &domain, const Space<T, 1, N> &image)
    {
        this->domain = domain;
        this->image = image;
    }

    ScalarField<T, M, N> derivative()
    {
        Space<T, 1, N> result_image{};

        for (std::size_t m = 0; m < M; m++)
        {
            result_image[m + 1] = (this->image[m + 1] - this->image[m]) / (this->domain[m + 1].magnitude() - this->domain[m].magnitude());
        }

        return ScalarField<T, M, N>(this->domain, result_image);
    }

    ScalarField<T, M, N> integral(std::size_t a, std::size_t b)
    {
        Space<T, 1, N> result_image{};

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
