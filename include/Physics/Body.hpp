#ifndef BODY_HPP
#define BODY_HPP

#include <array>
#include <cmath>
#include "AnalyticGeometry/Solid.hpp"
#include "LinearAlgebra/Space.hpp"

#include "Physics/ElectromagneticField.hpp"
#include "Physics/GravitationalField.hpp"

using analytic_geometry::Solid;

using physics::ElectromagneticField;
using physics::GravitationalField;

namespace physics
{
    template <std::size_t N>
    class Body : public Solid<double, N>
    {
    protected:
        double mass;
        ElectromagneticField<N> electromagnetic_field;
        GravitationalField<N> gravitational_field;

    public:
        Body()
        {

            this->mass = 0;
            this->set = linear_algebra::Space<double, 3, N>();
        }

        Body(double mass, const Space<double, 3, N> &set)
        {
            this->set = set;
            this->mass = mass;
        }

        linear_algebra::Space<double, 3, N> &getSet()
        {
            return this->set;
        }

        void setSet(linear_algebra::Space<double, 3, N> &set)
        {
            return this->set = set;
        }

        void setMass(double mass)
        {
            this->mass = mass;
        }

        double getMass()
        {
            return this->mass;
        }
    };
};

#endif