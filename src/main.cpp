#include <iostream>

#include "Physics/Body.hpp"
#include "Physics/Space.hpp"

#include <math.h>

int main()
{

        linear_algebra::Space<double, 3, 100> set;
        set[0] = linear_algebra::Vector<double, 3>({0, 10, 10});
        physics::Body<100> particle(10, set);

        physics::Space<100> space;

        space.addBody(particle);
        return 0;
}