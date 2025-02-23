#ifndef FIELD_H
#define FIELD_H

#include <array>
#include <cmath>
#include "Vector.hpp"

template <typename T, std::size_t N>
class Field
{
protected:
    std::array<T, N> subset;

public:
    Field()
    {
        subset.fill(T(0));
    }

    Field(std::array<T, N> subset) : subset(subset)
    {
    }

    std::array<T, N> &getSubset()
    {
        return subset;
    }

    void setSubset(std::array<T, N> &subset_values)
    {
        subset = subset_values;
    }

    Field operator+(Field &other)
    {
        std::array<T, N> result_subset{};
        std::array<T, N> other_subset = other.getSubset();

        for (std::size_t a = 0; a < N; a++)
        {
            result_subset[a] = subset[a] + other_subset[a];
        }

        return Field(result_subset);
    }

    Field operator+(std::array<T, N> scalars)
    {
        std::array<T, N> result_subset{};

        for (std::size_t a = 0; a < N; a++)
        {
            result_subset[a] = subset[a] + scalars[a];
        }

        return Field(result_subset);
    }

    Field &operator+=(Field &other)
    {
        std::array<T, N> other_subset = other.getSubset();

        for (std::size_t a = 0; a < N; a++)
        {
            subset[a] += other_subset[a];
        }

        return *this;
    }

    Field operator+(T scalar)
    {
        std::array<T, N> result_subset{};
        for (std::size_t a = 0; a < N; a++)
        {
            result_subset[a] = subset[a] + scalar;
        }

        return Field(result_subset);
    }

    Field &operator+=(T scalar)
    {
        for (std::size_t a = 0; a < N; a++)
        {
            subset[a] += scalar;
        }

        return *this;
    }

    Field &operator=(std::array<T, N> other)
    {
        for (std::size_t a = 0; a < N; a++)
        {
            subset[a] = other;
        }

        return *this;
    }

    Field operator-(Field &other)
    {
        std::array<T, N> result_subset{};
        std::array<T, N> other_subset = other.getImage();

        for (std::size_t a = 0; a < N; a++)
        {
            result_subset[a] = subset[a] - other_subset[a];
        }

        return Field(result_subset);
    }

    Field operator*(Field &other)
    {
        std::array<T, N> result_subset{};
        std::array<T, N> other_subset = other.getSubset();

        for (std::size_t a = 0; a < N; a++)
        {
            result_subset[a] = subset[a] * other_subset[a];
        }

        return Field(result_subset);
    }

    Field operator*(double other)
    {
        std::array<T, N> result_subset{};

        for (std::size_t a = 0; a < N; a++)
        {
            result_subset[a] = subset[a] * other;
        }

        return Field(result_subset);
    }

    T &operator[](std::size_t index)
    {
        return subset[index];
    }
};

#endif
