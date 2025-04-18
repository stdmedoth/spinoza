#include <iostream>

#include "Physics/Body.h"
#include "Physics/Space.h"

#include <math.h>

int main()
{
        physics::Space space;

        double mass = 9.1e-31;
        double e = 1.6e-19;
        double charge1 = 100 * e;
        double charge2 = 1 * e;
        physics::Body particle1(10 * mass, charge1, Vector<double, 3>({0, 0, 0}), Vector<double, 3>({0, 0, 0}));
        physics::Body particle2(mass, -100 * charge2, Vector<double, 3>({0, 100, 0}), Vector<double, 3>({15, 0, 0}));

        space.addBody(particle1);
        space.addBody(particle2);

        space.run(10000);

        return 0;
}