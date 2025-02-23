#ifndef VECTORSPACE_H
#define VECTORSPACE_H

#include <array>
#include <cmath>
#include "Vector.hpp"

template <typename T, std::size_t M, std::size_t N>
class VectorSpace
{
protected:
    std::array<Vector<T, M>, N> subset;

public:
    VectorSpace()
    {
        Vector<T, M> _subset;

        subset.fill(_subset);
    }

    VectorSpace(std::array<Vector<T, M>, N> subset) : subset(subset)
    {
    }

    std::array<Vector<T, M>, N> &getSubset()
    {
        return subset;
    }

    void setSubset(std::array<Vector<T, M>, N> &subset_values)
    {
        subset = subset_values;
    }

    VectorSpace operator+(VectorSpace &other)
    {
        std::array<Vector<T, M>, N> result_subset{};
        std::array<Vector<T, M>, N> other_subset = other.getSubset();

        for (std::size_t a = 0; a < N; a++)
        {
            for (std::size_t d = 0; d < M; d++)
            {
                result_subset[a][d] = subset[a][d] + other_subset[a][d];
            }
        }

        return VectorSpace(result_subset);
    }

    VectorSpace operator+(Vector<T, M> vector)
    {
        std::array<Vector<T, M>, N> result_subset{};

        for (std::size_t a = 0; a < N; a++)
        {
            for (std::size_t d = 0; d < M; d++)
            {
                result_subset[a][d] = subset[a][d] + vector[d];
            }
        }

        return VectorSpace(result_subset);
    }

    VectorSpace &operator+=(VectorSpace &other)
    {
        std::array<Vector<T, M>, N> other_subset = other.getSubset();

        for (std::size_t a = 0; a < N; a++)
        {
            for (std::size_t d = 0; d < M; d++)
            {
                subset[a][d] += other_subset[a][d];
            }
        }

        return *this;
    }

    VectorSpace &operator+=(Vector<T, M> &vector)
    {
        for (std::size_t a = 0; a < N; a++)
        {
            subset[a] += vector;
        }

        return *this;
    }

    VectorSpace &operator=(Vector<T, M> other)
    {
        for (std::size_t a = 0; a < N; a++)
        {
            subset[a] = other;
        }

        return *this;
    }

    VectorSpace operator-(VectorSpace &other)
    {
        std::array<T, N> result_subset{};
        std::array<T, N> other_subset = other.getImage();

        for (std::size_t a = 0; a < N; a++)
        {
            for (std::size_t d = 0; d < M; d++)
            {
                result_subset[a] = subset[a] - other_subset[a];
            }
        }

        return VectorSpace(result_subset);
    }

    VectorSpace operator*(VectorSpace &other)
    {
        std::array<Vector<T, M>, N> result_subset{};
        std::array<Vector<T, M>, N> other_subset = other.getSubset();

        for (std::size_t a = 0; a < N; a++)
        {
            for (std::size_t d = 0; d < M; d++)
            {
                result_subset[a][d] = subset[a][d] * other_subset[a][d];
            }
        }

        return VectorSpace(result_subset);
    }

    VectorSpace operator*(double other)
    {
        std::array<Vector<T, M>, N> result_subset{};

        for (std::size_t a = 0; a < N; a++)
        {
            for (std::size_t d = 0; d < M; d++)
            {
                result_subset[a][d] = subset[a][d] * other;
            }
        }

        return VectorSpace(result_subset);
    }

    Vector<T, M> &operator[](std::size_t index)
    {
        return subset[index];
    }
};

#endif
