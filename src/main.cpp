#include <iostream>

#include "Physics/Particle.h"
#include "Physics/Body.h"
#include "Physics/Space.h"
#include "Physics/Capacitor.h"

#include <math.h>

int main()
{
        physics::Space space;

        double mass = 9.1e-31;
        double e = 1.6e-19;
        double charge1 = 10 * e;
        double c = 3 * 1.e8;

        double ro = e / 100;

        physics::Capacitor capacitor1(ro, 1000, linear_algebra::Vector<double, 3>({0, 0, 0}), linear_algebra::Vector<double, 3>({0, 0, 0}));
        capacitor1.addToSpace(space);

        physics::Particle particle1(mass, 10 * charge1, linear_algebra::Vector<double, 3>({500, 600, 10}), linear_algebra::Vector<double, 3>({0, 0, 0}));
        space.addParticle(particle1);

        physics::Particle particle2(mass, -10 * charge1, linear_algebra::Vector<double, 3>({500, 400, -10}), linear_algebra::Vector<double, 3>({0, 0, 0}));
        space.addParticle(particle2);

        space.run(1000);

        return 0;
}