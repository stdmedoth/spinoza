#ifndef VECTORFUNCTION_H
#define VECTORFUNCTION_H

#include <array>
#include <cmath>
#include "VectorSpace.hpp"

template <typename T, std::size_t M, std::size_t N>
class VectorFunction
{

protected:
    VectorSpace<T, M, N> domain;
    VectorSpace<T, M, N> image;

public:
    Function()
    {
        this->domain = VectorSpace<T, M, N>();
        this->image = VectorSpace<T, M, N>();
    }

    Function(const VectorSpace<T, M, N> &domain, const VectorSpace<T, M, N> &image)
    {
        this->domain = domain;
        this->image = image;
    }

    VectorSpace<T, M, N> &getDomain()
    {
        return this->domain;
    }

    VectorSpace<T, M, N> &getImage()
    {
        return this->image;
    }

    void setDomain(VectorSpace<T, M, N> &domain)
    {
        this->domain = domain;
    }

    void setImage(VectorSpace<T, M, N> &image)
    {
        this->image = image;
    }

    Function operator+(Function &other)
    {
        VectorSpace<T, M, N> result_image{};
        VectorSpace<T, M, N> other_image = other.getImage();

        for (std::size_t a = 0; a < N; a++)
        {
            for (std::size_t d = 0; d < M; d++)
            {
                result_image[a][d] = this->image[a][d] + other_image[a][d];
            }
        }

        return Function(result_image);
    }

    Function operator+(Vector<T, M> vector)
    {
        VectorSpace<T, M, N> result_domain{};
        VectorSpace<T, M, N> result_image{};

        for (std::size_t a = 0; a < N; a++)
        {
            result_domain[a] = this->domain[a];
            for (std::size_t d = 0; d < M; d++)
            {
                result_image[a][d] = this->image[a][d] + vector[d];
            }
        }

        return Function(this->domain, result_image);
    }

    Function &operator+=(Function &other)
    {
        VectorSpace<T, M, N> result_domain{};
        VectorSpace<T, M, N> other_image = other.getImage();

        for (std::size_t a = 0; a < N; a++)
        {
            result_domain[a] = this->domain[a];
            for (std::size_t d = 0; d < M; d++)
            {
                this->image[a][d] += other_image[a][d];
            }
        }

        return *this;
    }

    Function &operator=(Vector<T, N> other)
    {
        for (std::size_t a = 0; a < N; a++)
        {
            this->image[a] = other;
        }

        return *this;
    }

    Function operator-(Function &other)
    {
        VectorSpace<T, M, N> result_domain{};
        VectorSpace<T, M, N> result_image{};
        VectorSpace<T, M, N> other_image = other.getImage();

        for (std::size_t a = 0; a < N; a++)
        {
            result_domain[a] = this->domain[a];
            for (std::size_t d = 0; d < M; d++)
            {
                result_image[a] = this->image[a] - other_image[a];
            }
        }

        return Function(this->domain, result_image);
    }

    Function operator*(Function &other)
    {
        VectorSpace<T, M, N> result_domain{};
        VectorSpace<T, M, N> result_image{};
        VectorSpace<T, M, N> other_image = other.getImage();

        for (std::size_t a = 0; a < N; a++)
        {
            result_domain[a] = this->domain[a];
            for (std::size_t d = 0; d < M; d++)
            {
                result_image[a][d] = this->image[a][d] * other_image[a][d];
            }
        }

        return Function(this->domain, result_image);
    }

    Function operator*(double &other)
    {
        VectorSpace<T, M, N> result_domain{};
        VectorSpace<T, M, N> result_image{};

        for (std::size_t a = 0; a < N; a++)
        {
            result_domain[a] = this->domain[a];
            for (std::size_t d = 0; d < M; d++)
            {
                result_image[a][d] = this->image[a][d] * other;
            }
        }

        return Function(this->domain, result_image);
    }

    Vector<T, N> &operator[](std::size_t index)
    {
        return image[index];
    }

    Function<T, M, N> derivative()
    {
    }

    Function<T, M, N> integral(std::size_t a, std::size_t b)
    {
    }
};

#endif
