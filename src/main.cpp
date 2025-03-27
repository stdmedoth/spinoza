#include <iostream>

#include "Physics/Body.h"
#include "Physics/Space.h"

#include <math.h>

int main()
{
        physics::Space space;

        double mass = 9.1e-31;
        double e = 1.6e-19;
        double charge1 = 10 * e;
        physics::Body particle1(5 * mass, 10 * charge1, Vector<double, 3>({100, 0, 0}), Vector<double, 3>({25, 25, 0}));
        physics::Body particle2(5 * mass, 10 * -charge1, Vector<double, 3>({-100, 0, 0}), Vector<double, 3>({0, -25, 0}));

        space.addBody(particle1);
        space.addBody(particle2);

        space.run(10000);

        return 0;
}