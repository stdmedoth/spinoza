#include "Physics/Capacitor.h"

using linear_algebra::Vector;

namespace physics
{

    Capacitor::Capacitor()
        : charge_density(0.0), distance(0.0), position({0.0, 0.0, 0.0}), velocity({0.0, 0.0, 0.0}) {}

    Capacitor::Capacitor(double charge_density, double distance, Vector<double, 3> position, Vector<double, 3> velocity)
        : charge_density(charge_density), distance(distance), position(position), velocity(velocity) {}

    void Capacitor::setChargeDensity(double charge_density)
    {
        this->charge_density = charge_density;
    }

    double Capacitor::getChargeDensity()
    {
        return charge_density;
    }

    void Capacitor::setDistance(double distance)
    {
        this->distance = distance;
    }

    double Capacitor::getDistance()
    {
        return distance;
    }

    void Capacitor::setPosition(Vector<double, 3> position)
    {
        this->position = position;
    }

    Vector<double, 3> Capacitor::getPosition()
    {
        return position;
    }

    void Capacitor::setVelocity(Vector<double, 3> velocity)
    {
        this->velocity = velocity;
    }

    Vector<double, 3> Capacitor::getVelocity()
    {
        return velocity;
    }

    void Capacitor::addToSpace(Space &space)
    {
        // Assuming Space has a method to add a Capacitor
        // build a plate of carges on y = 100 with charge1 and on y = -100 with -charge1
        double electron_mass = 9.1e-31;
        double dm = electron_mass / 1000;
        double charge = this->charge_density * 1000;

        for (int i = this->position[0]; i < this->distance; i += (this->distance / 10))
        {
            for (int j = this->position[1]; j < 1000; j += (this->distance / 10))
            {
                physics::Particle particle1(10e10 * dm, charge, linear_algebra::Vector<double, 3>({double(i), double(j), this->position[2] + this->distance}), linear_algebra::Vector<double, 3>({0, 0, 0}));
                space.addParticle(particle1);

                physics::Particle particle2(10e10 * dm, -charge, linear_algebra::Vector<double, 3>({double(i), double(j), -this->position[2] - this->distance}), linear_algebra::Vector<double, 3>({0, 0, 0}));
                space.addParticle(particle2);
            }
        }
    }
};