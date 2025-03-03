#include <cmath>
#include "Physics/Body.h"
#include "LinearAlgebra/Space.hpp"
#include "LinearAlgebra/Vector.hpp"

using linear_algebra::Vector;

namespace physics
{
    Body::Body()
    {
        this->mass = 0;
    }

    Body::Body(double mass)
    {
        this->mass = mass;
    }

    void Body::setMass(double mass)
    {
        this->mass = mass;
    }

    double Body::getMass()
    {
        return this->mass;
    }

    void Body::setPosition(Vector<double, 3> position)
    {
        this->position = position;
    }

    Vector<double, 3> Body::getPosition()
    {
        return this->position;
    }
};