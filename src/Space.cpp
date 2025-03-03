#include "Physics/Space.h"
#include "Physics/Body.h"

namespace physics
{
    Space::Space()
    {
    }

    void Space::addBody(const Body &body)
    {
        bodies.push_back(body);
    }
};
