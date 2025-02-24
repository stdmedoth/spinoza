#ifndef VECTORFIELD_HPP
#define VECTORFIELD_HPP

#include <array>
#include <cmath>
#include "Space.hpp"
#include "LinearTransformation.hpp"

template <typename T, std::size_t M, std::size_t N>
class VectorField : public LinearTransformation<T, M, N>
{
public:
    VectorField()
    {
        this->domain = Space<T, M, N>();
        this->image = Space<T, M, N>();
    }

    VectorField(const Space<T, M, N> &domain, const Space<T, M, N> &image)
    {
        this->domain = domain;
        this->image = image;
    }

    VectorField<T, M, N> derivative()
    {
        Space<T, M, N> result_image{};

        for (std::size_t m = 0; m < N; m++)
        {

            for (std::size_t dim = 0; dim < M; dim++)
            {
                result_image[m + 1][dim] = (this->image[m + 1][dim] - this->image[m][dim]) / (this->domain[m + 1][dim] - this->domain[m][dim]);
            }
        }

        return VectorField<T, M, N>(this->domain, result_image);
    }

    VectorField<T, M, N> integral(std::size_t a, std::size_t b)
    {
        Space<T, M, N> result_image{};

        for (std::size_t i = a; i < b; i++)
        {
            for (std::size_t j = 0; j < M; j++)
            {
                result_image[i + 1][j] = result_image[i][j] + this->image[i][j] * (this->domain[i + 1][j] - this->domain[i][j]);
            }
        }
        return VectorField<T, M, N>(this->domain, result_image);
    }

    Vector<T, N> &operator[](std::size_t index)
    {
        return this->image[index];
    }
};

#endif
