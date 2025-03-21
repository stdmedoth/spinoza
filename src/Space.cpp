#include <iostream>
#include <fstream>

#include "Physics/Space.h"
#include "Physics/Body.h"

namespace physics
{
    Space::Space()
    {
    }

    void Space::addBody(const Body &body)
    {
        this->bodies.push_back(body);
    }

    void Space::run(size_t loop_size = 10000)
    {
        double k = 8.99e9;
        double dt = 0.01;
        size_t bodies_len = this->bodies.size();
        size_t i3 = 0;

        for (size_t i = 0; i < bodies_len; i++)
        {
            std::ofstream output_file("body-" + std::to_string(i) + ".dat");
            output_file << "x,y" << "\n";
        }

        do
        {
            for (size_t i = 0; i < bodies_len; i++)
            {
                std::ofstream output_file("body-" + std::to_string(i) + ".dat", std::ios::app);

                // calculating collisions happening on body i
                /*
                for (size_t i2 = 0; i2 < bodies_len; i2++)
                {
                    Vector<double, 3> r;
                    r = this->bodies[i2].getPosition() - this->bodies[i].getPosition();
                    if (r.magnitude() <= dt * 10)
                    {
                        double m1 = this->bodies[i].getMass();
                        double m2 = this->bodies[i2].getMass();
                        double summedMass = m1 + m2;
                        double subtractedMass = m1 - m2;
                        Vector<double, 3> v1 = this->bodies[i].getVelocity();
                        Vector<double, 3> v2 = this->bodies[i2].getVelocity();

                        Vector<double, 3> _v1 = v1 * (subtractedMass) / (summedMass) + v2 * 2 * m2 / summedMass;
                        // this->bodies[i].setVelocity(_v1);
                        // this->bodies[i].setPosition(this->bodies[i].getPosition() + _v1 * dt);

                        Vector<double, 3> _v2 = v1 * 2 * m1 / summedMass - v2 * (subtractedMass) / (summedMass);
                        // this->bodies[i2].setVelocity(_v2);
                        // this->bodies[i2].setPosition(this->bodies[i2].getPosition() + _v2 * dt);
                    }
                }
                */
                // calculating eletric force acting from body i on i2
                Vector<double, 3> efi = Vector<double, 3>({0, 0, 0});
                for (size_t i2 = 0; i2 < bodies_len; i2++)
                {
                    if (i == i2)
                        continue;

                    Vector<double, 3> r = this->bodies[i2].getPosition() - this->bodies[i].getPosition();
                    double r_mag = r.magnitude();

                    if (r_mag < 1)
                    {
                        continue; // Avoid big forces on collision
                    }

                    Vector<double, 3> unitr = r / r_mag;

                    // repulsive or attractive
                    double charge_product = this->bodies[i2].getCharge() * this->bodies[i].getCharge();
                    efi = efi + unitr * k * (fabs(charge_product) / (r_mag * r_mag)) * ((charge_product > 0) ? -1 : 1);
                }
                Vector<double, 3> a = efi * (1 / this->bodies[i].getMass());
                Vector<double, 3> v = this->bodies[i].getVelocity();

                this->bodies[i].setVelocity(this->bodies[i].getVelocity() + a * dt);
                this->bodies[i].setPosition(this->bodies[i].getPosition() + this->bodies[i].getVelocity() * dt);

                Vector<double, 3> position = this->bodies[i].getPosition();
                output_file << position[0] << "," << position[1] << "\n";
            }
        } while (i3++ < loop_size);
    }
};
