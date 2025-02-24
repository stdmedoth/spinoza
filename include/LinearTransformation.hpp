#ifndef LINEARTRANSFORMATION_H
#define LINEARTRANSFORMATION_H

#include <array>
#include <cmath>

#include "VectorFunction.hpp"

template <typename T, std::size_t M, std::size_t N>
class LinearTransformation : public VectorFunction<T, M, N>
{
public:
    LinearTransformation()
    {
        this->domain = Space<T, M, N>();
        this->image = Space<T, M, N>();
    }

    LinearTransformation(const Space<T, M, N> &domain, const Space<T, M, N> &image)
    {
        this->domain = domain;
        this->image = image;
    }
};

#endif
