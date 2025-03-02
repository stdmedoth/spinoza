
#ifndef GEOMETRICOBJECT_HPP
#define GEOMETRICOBJECT_HPP

#include "LinearAlgebra/Space.hpp"

using linear_algebra::Space;
using linear_algebra::Vector;

namespace analytic_geometry
{
    template <typename T, std::size_t M, std::size_t N>
    class GeometricObject
    {
    protected:
        Space<T, M, N> set;

    public:
        GeometricObject()
        {
            this->set = Space<T, M, N>();
        }
        GeometricObject(const Space<T, M, N> &set)
        {
            this->set = set;
        }

        Space<T, M, N> getSet()
        {
            return this->set;
        }

        Vector<T, M> &operator[](std::size_t index)
        {
            return this->set[index];
        }
    };
};

#endif
