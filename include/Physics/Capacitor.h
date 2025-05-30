#ifndef CAPACITOR_H
#define CAPACITOR_H

#include <array>
#include <cmath>
#include "LinearAlgebra/Vector.hpp"

#include "Physics/Space.h"

using linear_algebra::Vector;
using physics::Space;

namespace physics
{
    class Capacitor
    {
    protected:
        double charge_density;
        double distance;
        Vector<double, 3> position;
        Vector<double, 3> velocity;

    public:
        Capacitor();

        Capacitor(double, double, Vector<double, 3>, Vector<double, 3>);

        void setChargeDensity(double);

        double getChargeDensity();

        void setDistance(double);

        double getDistance();

        void setPosition(Vector<double, 3>);

        Vector<double, 3> getPosition();

        void setVelocity(Vector<double, 3>);

        Vector<double, 3> getVelocity();

        void addToSpace(Space &space);
    };
};

#endif