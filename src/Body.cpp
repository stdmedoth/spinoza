#include <cmath>
#include "Physics/Body.h"
#include "Physics/Particle.h"
#include "LinearAlgebra/Space.hpp"
#include "LinearAlgebra/Vector.hpp"

using linear_algebra::Vector;

namespace physics
{
    Body::Body()
    {
        this->mass = 0;
        this->charge = 0;
        this->particles = std::vector<Particle>();
        this->cm_position = Vector<double, 3>({0, 0, 0});
        this->cm_velocity = Vector<double, 3>({0, 0, 0});
    }

    Body::Body(std::vector<Particle> particles, double mass, double charge, Vector<double, 3> position, Vector<double, 3> velocity)
    {
        this->particles = particles;

        this->mass = 0;
        Vector<double, 3> cm_position;
        Vector<double, 3> cm_velocity;
        for (size_t i = 0; i < particles.size(); i++)
        {
            this->mass += particles[i].getMass();
            this->charge += particles[i].getCharge();
            cm_position = cm_position + particles[i].getPosition() * particles[i].getMass();
            cm_velocity = cm_velocity + particles[i].getVelocity() * particles[i].getMass();
        }
        this->cm_position = cm_position / this->mass;
        this->cm_velocity = cm_velocity / this->mass;
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
        this->cm_position = position;
    }

    Vector<double, 3> Body::getPosition()
    {
        return this->cm_position;
    }

    void Body::setVelocity(Vector<double, 3> velocity)
    {
        this->cm_velocity = velocity;
    }

    Vector<double, 3> Body::getVelocity()
    {
        return this->cm_velocity;
    }

    void Body::addParticle(Particle particle)
    {
        this->particles.push_back(particle);
    }
    void Body::setParticles(std::vector<Particle> particles)
    {
        this->particles = particles;
    }

    std::vector<Particle> Body::getParticles()
    {
        return this->particles;
    }
};