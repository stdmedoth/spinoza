#ifndef LINEARTRANSFORMATION_H
#define LINEARTRANSFORMATION_H

#include <array>
#include <cmath>

#include "Function.hpp"

template <typename T, std::size_t M, std::size_t N>
class LinearTransformation : public Function<T, M, N>
{
public:
    LinearTransformation()
    {
        this->domain = VectorSpace<T, M, N>();
        this->image = VectorSpace<T, M, N>();
    }

    LinearTransformation(const VectorSpace<T, M, N> &domain, const VectorSpace<T, M, N> &image)
    {
        this->domain = domain;
        this->image = image;
    }
};

#endif
