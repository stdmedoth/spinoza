#ifndef ELECTROMAGNETICFIELD_HPP
#define ELECTROMAGNETICFIELD_HPP

#include <array>
#include <cmath>
#include "LinearAlgebra/VectorField.hpp"

using linear_algebra::VectorField;

namespace physics
{

    template <std::size_t N>
    class ElectromagneticField : public VectorField<double, 3, N>
    {
    public:
    protected:
    };
};

#endif