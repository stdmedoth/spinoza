
#ifndef SURFACE_HPP
#define SURFACE_HPP

#include <array>
#include <cmath>

#include "AnalyticGeometry/GeometricObject.hpp"

namespace analytic_geometry
{
    template <typename T, std::size_t N>
    class Surface : public GeometricObject<T, 2, N>
    {
    public:
    };
};

#endif
