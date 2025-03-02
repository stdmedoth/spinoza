#ifndef GRAVITATIONALFIELD_HPP
#define GRAVITATIONALFIELD_HPP

#include <array>
#include <cmath>
#include "LinearAlgebra/VectorField.hpp"

namespace physics
{

    template <std::size_t N>
    class GravitationalField : public linear_algebra::VectorField<double, 3, N>
    {
    public:
    protected:
    };
};

#endif