#ifndef VECTORFIELD_HPP
#define VECTORFIELD_HPP

#include <array>
#include <cmath>
#include "Space.hpp"
#include "LinearTransformation.hpp"

template <typename T, std::size_t M, std::size_t N>
class VectorField : public LinearTransformation<T, M, N>
{
public:
    VectorField()
    {
        this->domain = Space<T, M, N>();
        this->image = Space<T, M, N>();
    }

    VectorField(const Space<T, M, N> &domain, const Space<T, M, N> &image)
    {
        this->domain = domain;
        this->image = image;
    }

    Vector<T, N> &operator[](std::size_t index)
    {
        return this->image[index];
    }
};

#endif
