#ifndef LINEAR_ALGEBRA_SPACE_HPP
#define LINEAR_ALGEBRA_SPACE_HPP

#include <array>
#include <cmath>
#include "LinearAlgebra/Vector.hpp"
#include <tuple>

namespace linear_algebra
{
    template <typename T, std::size_t M, std::size_t N>
    class Space
    {
    protected:
        std::array<Vector<T, M>, N> subset;

    public:
        Space()
        {
            subset.fill(Vector<T, M>());
        }

        Space(std::array<Vector<T, M>, N> subset) : subset(subset)
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

        std::tuple<std::array<std::size_t, N>, std::size_t> parametrize(Space<T, M, N> other, double precision)
        {
            std::size_t index = 0;
            std::array<std::size_t, N> parameterization;
            for (std::size_t i = 0; i < N; i++)
            {
                for (size_t i2 = 0; i2 < N; i2++)
                {
                    double distance = std::abs((this->subset[i] - other[i2]).magnitude());
                    if ((distance != 0) && (distance < precision))
                    {
                        parameterization[index] = i;
                        index++;
                    }
                }
            }

            return std::make_tuple(parameterization, index);
        }

        Space operator+(Space &other)
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

            return Space(result_subset);
        }

        Space operator+(Vector<T, M> vector)
        {
            std::array<Vector<T, M>, N> result_subset{};

            for (std::size_t a = 0; a < N; a++)
            {
                for (std::size_t d = 0; d < M; d++)
                {
                    result_subset[a][d] = subset[a][d] + vector[d];
                }
            }

            return Space(result_subset);
        }

        Space &operator+=(Space &other)
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

        Space &operator+=(Vector<T, M> &vector)
        {
            for (std::size_t a = 0; a < N; a++)
            {
                subset[a] += vector;
            }

            return *this;
        }

        Space &operator=(Vector<T, M> other)
        {
            for (std::size_t a = 0; a < N; a++)
            {
                subset[a] = other;
            }

            return *this;
        }

        Space operator-(Space &other)
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

            return Space(result_subset);
        }

        Space operator*(Space &other)
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

            return Space(result_subset);
        }

        Space operator*(double other)
        {
            std::array<Vector<T, M>, N> result_subset{};

            for (std::size_t a = 0; a < N; a++)
            {
                for (std::size_t d = 0; d < M; d++)
                {
                    result_subset[a][d] = subset[a][d] * other;
                }
            }

            return Space(result_subset);
        }

        Vector<T, M> &operator[](std::size_t index)
        {
            return subset[index];
        }
    };
};

#endif
