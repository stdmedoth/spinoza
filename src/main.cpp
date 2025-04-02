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

        physics::Body circle;
        size_t particles_qnt = 30;
        for (size_t i = 0; i < particles_qnt; i++)
        {
                double x = 100 * std::sin((2 * M_PI * i) / particles_qnt);
                double y = 100 * std::cos((2 * M_PI * i) / particles_qnt);
                linear_algebra::Vector<double, 3> position = linear_algebra::Vector<double, 3>({x, y, 0});
                physics::Particle particle(mass, charge1, position, linear_algebra::Vector<double, 3>({0, 0.00000125 * c, 0}));
                circle.addParticle(particle);
        }

        space.addBody(circle);

        space.run(500);

        return 0;
}