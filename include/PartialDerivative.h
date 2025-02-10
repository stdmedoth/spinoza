#ifndef PARTIAL_DERIVATIVE_H

#define PARTIAL_DERIVATIVE_H

#include <array>

template <typename T, std::size_t N>
class PartialDerivative
{
private:
    std::array<T, N> x;
    std::array<T, N> y;

public:
    PartialDerivative(std::array<T, N> &x, std::array<T, N> &y) : x(x), y(y) {}

    T operator[](std::size_t i)
    {
        T derivative = (y[i + 1] - y[i]) / 1;
        return derivative;
    }

    std::array<T, N - 1> computeAll() const
    {
        std::array<T, N - 1> derivatives;
        for (std::size_t i = 0; i < N - 1; i++)
        {
            derivatives[i] = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
        }
        return derivatives;
    }
};

#endif