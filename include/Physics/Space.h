#ifndef PHYSICS_SPACE_H
#define PHYSICS_SPACE_H
#include <vector>
#include <cmath>

#include "LinearAlgebra/Space.hpp"
#include "Physics/Body.h"

namespace physics
{
    class Space
    {
    protected:
        std::vector<Body> bodies;

    public:
        Space();

        void addBody(const Body &body);

        void run();
    };
};

#endif
