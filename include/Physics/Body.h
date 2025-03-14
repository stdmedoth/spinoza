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
        double charge;
        Vector<double, 3> position;
        Vector<double, 3> velocity;

    public:
        Body();

        Body(double, double, Vector<double, 3>, Vector<double, 3>);

        void setMass(double);

        double getMass();

        void setCharge(double);

        double getCharge();

        void setPosition(Vector<double, 3>);

        Vector<double, 3> getPosition();

        void setVelocity(Vector<double, 3>);

        Vector<double, 3> getVelocity();
    };
};

#endif