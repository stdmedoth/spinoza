#ifndef FUNCTION_H
#define FUNCTION_H

#include <array>
#include <cmath>
#include "Vector.hpp"

template <typename T, std::size_t M, std::size_t N>
class Function
{

private:
public:
    Function(std::array<Vector<T, M>, N> domain, std::array<Vector<T, M>, N> image) : domain(domain), image(image)
    {
    }
    std::array<Vector<T, M>, N> domain;
    std::array<Vector<T, M>, N> image;

    Function<T, M, N> derivative()
    {
        std::array<Vector<T, M>, N> result_domain{};
        std::array<Vector<T, M>, N> result_image{};

        for (std::size_t i = 0; i < N - 1; i++)
        {
            result_domain[i] = domain[i];

            for (std::size_t d = 0; d < M; d++)
            {
                result_image[i + 1][d] = (image[i + 1][d] - image[i][d]) / (domain[i + 1][d] - domain[i][d]);
            }
        }
        Function<T, M, N> result(result_domain, result_image);
        return result;
    }

    Function<T, M, N> integral(std::size_t a, std::size_t b)
    {
        std::array<Vector<T, M>, N> result_domain{};
        std::array<Vector<T, M>, N> result_image{};

        for (std::size_t d = 0; d < M; d++)
        {
            result_image[a][d] = image[a][d] * (domain[a + 1][d] - domain[a][d]);
        }
        for (std::size_t i = a; i < b - 1; i++)
        {
            result_domain[i] = domain[i];

            for (std::size_t d = 0; d < M; d++)
            {
                result_image[i + 1][d] = result_image[i][d] + image[i][d] * (domain[i + 1][d] - domain[i][d]);
            }
        }
        Function<T, M, N> result(result_domain, result_image);
        return result;
    }

    std::array<Vector<T, M>, N> &getDomain()
    {
        return domain;
    }

    std::array<Vector<T, M>, N> &getImage()
    {
        return image;
    }
};

#endif
