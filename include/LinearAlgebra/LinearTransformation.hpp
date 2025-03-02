#ifndef LINEARTRANSFORMATION_HPP
#define LINEARTRANSFORMATION_HPP

#include <array>
#include <cmath>

#include "Calculus/VectorFunction.hpp"

using calculus::VectorFunction;

namespace linear_algebra
{
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
};

#endif
