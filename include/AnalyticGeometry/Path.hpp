
#ifndef PATH_HPP
#define PATH_HPP

#include <array>
#include <cmath>

#include "AnalyticGeometry/GeometricObject.hpp"

namespace analytic_geometry
{
    template <typename T, std::size_t N>
    class Path : public GeometricObject<T, 1, N>
    {
    public:
    };
};

#endif
