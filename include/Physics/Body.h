#ifndef BODY_H
#define BODY_H

#include <array>
#include <vector>
#include <cmath>
#include "LinearAlgebra/Space.hpp"
#include "Physics/Particle.h"

using linear_algebra::Vector;

namespace physics
{
    class Body
    {
    protected:
        std::vector<Particle> particles;
        double mass;
        double charge;
        Vector<double, 3> cm_position;
        Vector<double, 3> cm_velocity;

    public:
        Body();

        Body(std::vector<Particle> particles, double mass, double charge, Vector<double, 3> position, Vector<double, 3> velocity);

        void setMass(double);

        double getMass();

        void setCharge(double);

        double getCharge();

        void setPosition(Vector<double, 3>);

        Vector<double, 3> getPosition();

        void setVelocity(Vector<double, 3>);

        Vector<double, 3> getVelocity();

        void setParticles(std::vector<Particle>);

        std::vector<Particle> getParticles();

        void addParticle(Particle particle);
    };
};

#endif