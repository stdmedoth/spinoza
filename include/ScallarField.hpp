#ifndef SCALLARFIELD_H
#define SCALLARFIELD_H

#include <array>
#include <cmath>
#include "VectorSpace.hpp"

template <typename T, std::size_t M, std::size_t N>
class ScallarField : public LinearTransformation
{

protected:
    VectorSpace<T, 1, N> domain;

public:
    ScallarField<T, M, N> derivative()
    {
        VectorSpace<T, 1, N> result_domain{};
        VectorSpace<T, M, N> result_image{};

        for (std::size_t m = 0; m < M - 1; m++)
        {
            result_domain[m] = domain[m];

            for (std::size_t dim = 0; dim < N; dim++)
            {
                result_image[m + 1][dim] = (image[m + 1][dim] - image[m][dim]) / (domain[m + 1][0] - domain[m][0]);
            }
        }

        return ScallarField<T, M, N>(result_domain, result_image);
    }

    ScallarField<T, M, N> integral(std::size_t a, std::size_t b)
    {
        VectorSpace<T, 1, N> result_domain{};
        std::array<Vector<T, M>, N> result_image{};

        for (std::size_t i = a; i < b - 1; i++)
        {
            result_domain[i] = domain[i];

            for (std::size_t j = 0; j < M; j++)
            {
                result_image[i + 1][j] = result_image[i][j] + image[i][j] * (domain[i + 1][0] - domain[i][0]);
            }
        }
        return ScallarField<T, M, N>(result_domain, result_image);
    }

    Vector<T, N> &operator[](std::size_t index)
    {
        return image[index];
    }
};

#endif
