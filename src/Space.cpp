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
        double mi0 = 4 * M_PI * 1e-7;
        size_t bodies_len = this->bodies.size();
        size_t i3 = 0;

        for (size_t i = 0; i < bodies_len; i++)
        {
            std::ofstream position_output_file("body-position-" + std::to_string(i) + ".dat");
            std::ofstream velocity_output_file("body-velocity-" + std::to_string(i) + ".dat");
            position_output_file << "x,y" << "\n";
            velocity_output_file << "x,y" << "\n";
        }

        do
        {
            for (size_t i = 0; i < bodies_len; i++)
            {
                std::ofstream position_output_file("body-position-" + std::to_string(i) + ".dat", std::ios::app);
                std::ofstream velocity_output_file("body-velocity-" + std::to_string(i) + ".dat", std::ios::app);

                Vector<double, 3> efi = Vector<double, 3>({0, 0, 0});
                Vector<double, 3> mfi = Vector<double, 3>({0, 0, 0});
                for (size_t i2 = 0; i2 < bodies_len; i2++)
                {
                    if (i == i2)
                        continue;

                    Vector<double, 3> r = this->bodies[i2].getPosition() - this->bodies[i].getPosition();
                    double r_mag = r.magnitude();
                    Vector<double, 3> unitr = r / r_mag;

                    // calculating eletric force acting from body i on i2
                    double charge_product = this->bodies[i2].getCharge() * this->bodies[i].getCharge();
                    efi = efi + unitr * k * (fabs(charge_product) / (r_mag * r_mag)) * ((charge_product > 0) ? -1 : 1);

                    // calculating magnetic force acting from body i on i2
                    Vector<double, 3> v1 = bodies[i].getVelocity();
                    Vector<double, 3> v2 = bodies[i2].getVelocity();

                    double prefactor = (mi0 / (4 * M_PI)) * charge_product / (r_mag * r_mag);
                    Vector<double, 3> term1 = v2 * (v1 * unitr);
                    Vector<double, 3> term2 = unitr * (v1 * v2);
                    mfi = mfi + (term1 - term2) * prefactor;
                }

                Vector<double, 3> elec_a = efi * (1 / this->bodies[i].getMass());
                Vector<double, 3> mag_a = mfi * (1 / this->bodies[i].getMass());
                Vector<double, 3> total_a = elec_a + mag_a;

                Vector<double, 3> v1 = this->bodies[i].getVelocity();
                Vector<double, 3> r1 = this->bodies[i].getPosition();

                Vector<double, 3> new_v = v1 + total_a * dt;
                this->bodies[i].setVelocity(new_v);
                this->bodies[i].setPosition(r1 + new_v * dt);

                Vector<double, 3> position = this->bodies[i].getPosition();
                position_output_file << position[0] << "," << position[1] << "\n";

                Vector<double, 3> velocity = this->bodies[i].getVelocity();
                velocity_output_file << velocity[0] << "," << velocity[1] << "\n";
            }
        } while (i3++ < loop_size);
    }
};
