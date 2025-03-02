#ifndef SCALARFUNCTION_HPP
#define SCALARFUNCTION_HPP

#include <array>
#include <cmath>
#include "LinearAlgebra/Space.hpp"

template <typename T, std::size_t M, std::size_t N>
class ScalarFunction
{

protected:
    Space<T, M, N> domain;
    Space<T, 1, N> image;

public:
    ScalarFunction()
    {
        this->domain = Space<T, M, N>();
        this->image = Space<T, 1, N>();
    }

    ScalarFunction(const Space<T, M, N> &domain, const Space<T, 1, N> &image)
    {
        this->domain = domain;
        this->image = image;
    }

    Space<T, M, N> &getDomain()
    {
        return this->domain;
    }

    Space<T, 1, N> &getImage()
    {
        return this->image;
    }

    void setDomain(Space<T, M, N> &domain)
    {
        this->domain = domain;
    }

    void setImage(Space<T, 1, N> &image)
    {
        this->image = image;
    }

    ScalarFunction operator+(ScalarFunction &other)
    {
        Space<T, 1, N> result_image{};
        Space<T, 1, N> other_image = other.getImage();

        for (std::size_t a = 0; a < N; a++)
        {
            for (std::size_t d = 0; d < M; d++)
            {
                result_image[a] = this->image[a] + other_image[a];
            }
        }

        return ScalarFunction(this->domain, result_image);
    }

    ScalarFunction operator+(T scalar)
    {
        Space<T, M, N> result_domain{};
        Space<T, 1, N> result_image{};

        for (std::size_t a = 0; a < N; a++)
        {
            result_domain[a] = this->domain[a];
            result_image[a] = this->image[a] + scalar;
        }

        return ScalarFunction(this->domain, result_image);
    }

    ScalarFunction &operator+=(ScalarFunction &other)
    {
        Space<T, M, N> result_domain{};
        Space<T, 1, N> other_image = other.getImage();

        for (std::size_t a = 0; a < N; a++)
        {
            result_domain[a] = this->domain[a];
            this->image[a] += other_image[a];
        }

        return *this;
    }

    ScalarFunction &operator=(T other)
    {
        for (std::size_t a = 0; a < N; a++)
        {
            this->image[a] = other;
        }

        return *this;
    }

    ScalarFunction operator-(ScalarFunction &other)
    {
        Space<T, M, N> result_domain{};
        Space<T, 1, N> result_image{};
        Space<T, 1, N> other_image = other.getImage();

        for (std::size_t a = 0; a < N; a++)
        {
            result_domain[a] = this->domain[a];
            result_image[a] = this->image[a] - other_image[a];
        }

        return ScalarFunction(this->domain, result_image);
    }

    ScalarFunction operator*(ScalarFunction &other)
    {
        Space<T, M, N> result_domain{};
        Space<T, 1, N> result_image{};
        Space<T, M, N> other_image = other.getImage();

        for (std::size_t a = 0; a < N; a++)
        {
            result_domain[a] = this->domain[a];
            result_image[a] = this->image[a] * other_image[a];
        }

        return ScalarFunction(this->domain, result_image);
    }

    ScalarFunction operator*(double &other)
    {
        Space<T, M, N> result_domain{};
        Space<T, 1, N> result_image{};

        for (std::size_t a = 0; a < N; a++)
        {
            result_domain[a] = this->domain[a];
            result_image[a] = this->image[a] * other;
        }

        return ScalarFunction(this->domain, result_image);
    }

    T &operator[](std::size_t index)
    {
        return image[index];
    }

    ScalarFunction<T, M, N> derivative()
    {
    }

    ScalarFunction<T, M, N> integral(std::size_t a, std::size_t b)
    {
    }
};

#endif
