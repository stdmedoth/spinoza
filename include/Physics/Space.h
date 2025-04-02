#ifndef PHYSICS_SPACE_H
#define PHYSICS_SPACE_H
#include <vector>
#include <cmath>

#include "LinearAlgebra/Space.hpp"
#include "Physics/Particle.h"
#include "Physics/Body.h"

namespace physics
{
    class Space
    {
    protected:
        std::vector<Particle> particles;

    public:
        Space();

        void addParticle(const Particle &particle);

        void addBody(Body &body);

        void run(size_t loop_size);
    };
};

#endif
