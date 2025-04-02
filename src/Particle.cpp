#include <cmath>
#include "Physics/Particle.h"
#include "LinearAlgebra/Space.hpp"
#include "LinearAlgebra/Vector.hpp"

using linear_algebra::Vector;

namespace physics
{
    Particle::Particle()
    {
        this->mass = 0;
        this->charge = 0;
        this->position = Vector<double, 3>({0, 0, 0});
        this->velocity = Vector<double, 3>({0, 0, 0});
    }

    Particle::Particle(double mass, double charge, Vector<double, 3> position, Vector<double, 3> velocity)
    {
        this->mass = mass;
        this->charge = charge;
        this->position = position;
        this->velocity = velocity;
    }

    void Particle::setMass(double mass)
    {
        this->mass = mass;
    }

    double Particle::getMass()
    {
        return this->mass;
    }

    void Particle::setCharge(double charge)
    {
        this->charge = charge;
    }

    double Particle::getCharge()
    {
        return this->charge;
    }

    void Particle::setPosition(Vector<double, 3> position)
    {
        this->position = position;
    }

    Vector<double, 3> Particle::getPosition()
    {
        return this->position;
    }

    void Particle::setVelocity(Vector<double, 3> velocity)
    {
        this->velocity = velocity;
    }

    Vector<double, 3> Particle::getVelocity()
    {
        return this->velocity;
    }
};