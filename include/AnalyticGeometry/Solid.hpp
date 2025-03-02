

#ifndef SOLID_HPP
#define SOLID_HPP

#include <array>
#include <cmath>

#include "AnalyticGeometry/GeometricObject.hpp"

namespace analytic_geometry
{
    template <typename T, std::size_t N>
    class Solid : public GeometricObject<T, 3, N>
    {
    public:
    };
};

#endif
