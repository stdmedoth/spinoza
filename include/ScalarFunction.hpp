#ifndef FUNCTION_H
#define FUNCTION_H

#include <array>
#include <cmath>
#include "VectorSpace.hpp"
#include "Field.hpp"

template <typename T, std::size_t M, std::size_t N>
class ScalarFunction
{

protected:
    VectorSpace<T, M, N> domain;
    Field<T, N> image;

public:
    ScalarFunction()
    {
        this->domain = VectorSpace<T, M, N>();
        this->image = Field<T, N>();
    }

    ScalarFunction(const VectorSpace<T, M, N> &domain, const Field<T, N> &image)
    {
        this->domain = domain;
        this->image = image;
    }

    VectorSpace<T, M, N> &getDomain()
    {
        return this->domain;
    }

    Field<T, N> &getImage()
    {
        return this->image;
    }

    void setDomain(VectorSpace<T, M, N> &domain)
    {
        this->domain = domain;
    }

    void setImage(Field<T, N> &image)
    {
        this->image = image;
    }

    ScalarFunction operator+(ScalarFunction &other)
    {
        Field<T, N> result_image{};
        Field<T, N> other_image = other.getImage();

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
        VectorSpace<T, M, N> result_domain{};
        Field<T, N> result_image{};

        for (std::size_t a = 0; a < N; a++)
        {
            result_domain[a] = this->domain[a];
            result_image[a] = this->image[a] + scalar;
        }

        return ScalarFunction(this->domain, result_image);
    }

    ScalarFunction &operator+=(ScalarFunction &other)
    {
        VectorSpace<T, M, N> result_domain{};
        Field<T, N> other_image = other.getImage();

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
        VectorSpace<T, M, N> result_domain{};
        Field<T, N> result_image{};
        Field<T, N> other_image = other.getImage();

        for (std::size_t a = 0; a < N; a++)
        {
            result_domain[a] = this->domain[a];
            result_image[a] = this->image[a] - other_image[a];
        }

        return ScalarFunction(this->domain, result_image);
    }

    ScalarFunction operator*(ScalarFunction &other)
    {
        VectorSpace<T, M, N> result_domain{};
        Field<T, N> result_image{};
        VectorSpace<T, M, N> other_image = other.getImage();

        for (std::size_t a = 0; a < N; a++)
        {
            result_domain[a] = this->domain[a];
            result_image[a] = this->image[a] * other_image[a];
        }

        return ScalarFunction(this->domain, result_image);
    }

    ScalarFunction operator*(double &other)
    {
        VectorSpace<T, M, N> result_domain{};
        Field<T, N> result_image{};

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
