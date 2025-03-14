#include <iostream>

#include "Physics/Body.h"
#include "Physics/Space.h"

#include <math.h>

int main()
{
        physics::Space space;

        double mass = 9.1 * std::pow(10, -31);
        double charge = 10 * 1.6 * std::pow(10, -19);
        physics::Body particle1(mass, charge, Vector<double, 3>({-100, 0, 0}), Vector<double, 3>({0, 4, 0}));
        physics::Body particle2(mass, -charge, Vector<double, 3>({0, 50, 0}), Vector<double, 3>({4, 0, 0}));

        space.addBody(particle1);
        space.addBody(particle2);

        space.run();

        return 0;
}