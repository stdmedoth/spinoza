#include <iostream>

#include "Physics/Particle.h"
#include "Physics/Body.h"
#include "Physics/Space.h"

#include <math.h>

int main()
{
        physics::Space space;

        double mass = 9.1e-31;
        double e = 1.6e-19;
        double charge1 = 10 * e;
        double c = 3 * 1.e8;

        physics::Particle particle1(mass, 3*charge1, linear_algebra::Vector<double, 3>({100, 0, 0}), linear_algebra::Vector<double, 3>({10, 15, 0}));
        space.addParticle(particle1);

        physics::Particle particle2(mass, -3*charge1, linear_algebra::Vector<double, 3>({-100, 0 , 0}), linear_algebra::Vector<double, 3>({10, -15, 0}));
        space.addParticle(particle2);

        space.run(10000);

        return 0;
}