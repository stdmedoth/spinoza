#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <array>
#include <cmath>
#include <iostream>

template <typename T, std::size_t N>
class Vector
{
private:
    std::array<T, N> data;

public:
    Vector() { data.fill(T(0)); }
    Vector(const std::array<T, N> &values) { data = values; }

    T &operator[](std::size_t i)
    {
        return data[i];
    }

    const T &operator[](std::size_t i) const { return data[i]; }

    void setPoint(const std::array<T, N> &values) { data = values; }

    std::array<T, N> getPoint() const { return data; }

    Vector operator+(const Vector &other) const
    {
        Vector result;
        for (std::size_t i = 0; i < N; i++)
        {
            result[i] = data[i] + other[i];
        }

        return result;
    }

    Vector operator-(const Vector &other) const
    {
        Vector result;
        for (std::size_t i = 0; i < N; i++)
        {
            result[i] = data[i] - other[i];
        }
        return result;
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector<T, N> &vec)
    {
        os << "[";
        for (std::size_t i = 0; i < N; i++)
        {
            os << vec[i];
            if (i < N - 1)
                os << ", ";
        }
        os << "]";
        return os;
    }

    int dot(const Vector &other)
    {
        int result;
        for (std::size_t i = 0; i < N; i++)
        {
            result += data[i] * other[i];
        }
        return result;
    }

    int dot()
    {
        int result;
        for (std::size_t i = 0; i < N; i++)
        {
            result += data[i] * data[i];
        }
        return result;
    }

    int getMagnitude()
    {
        return sqrt(dot());
    }
};

#endif