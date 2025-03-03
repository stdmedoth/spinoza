#include <iostream>

#include "Physics/Body.h"
#include "Physics/Space.h"

#include <math.h>

int main()
{

        linear_algebra::Space<double, 3, 100> set;
        set[0] = linear_algebra::Vector<double, 3>({0, 10, 10});
        physics::Body particle(10);

        physics::Space space;

        space.addBody(particle);

        return 0;
}