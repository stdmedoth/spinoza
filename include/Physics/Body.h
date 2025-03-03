#ifndef BODY_H
#define BODY_H

#include <array>
#include <cmath>
#include "LinearAlgebra/Space.hpp"

using linear_algebra::Vector;

namespace physics
{
    class Body
    {
    protected:
        double mass;
        Vector<double, 3> position;

    public:
        Body();

        Body(double);

        void setMass(double);

        double getMass();

        void setPosition(Vector<double, 3>);

        Vector<double, 3> getPosition();
    };
};

#endif