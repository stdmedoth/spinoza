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
        this->charge = 0;
        this->position = Vector<double, 3>({0, 0, 0});
        this->velocity = Vector<double, 3>({0, 0, 0});
    }

    Body::Body(double mass, double charge, Vector<double, 3> position, Vector<double, 3> velocity)
    {
        this->mass = mass;
        this->charge = charge;
        this->position = position;
        this->velocity = velocity;
    }

    void Body::setMass(double mass)
    {
        this->mass = mass;
    }

    double Body::getMass()
    {
        return this->mass;
    }

    void Body::setCharge(double charge)
    {
        this->charge = charge;
    }

    double Body::getCharge()
    {
        return this->charge;
    }

    void Body::setPosition(Vector<double, 3> position)
    {
        this->position = position;
    }

    Vector<double, 3> Body::getPosition()
    {
        return this->position;
    }

    void Body::setVelocity(Vector<double, 3> velocity)
    {
        this->velocity = velocity;
    }

    Vector<double, 3> Body::getVelocity()
    {
        return this->velocity;
    }
};