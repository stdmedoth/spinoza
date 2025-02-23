#include <iostream>
#include <fstream>

#include "VectorField.hpp"
#include "ScalarField.hpp"

#include "Space.hpp"

int main()
{
    std::ofstream output_file("bicycle_racing2.dat");
    output_file << "x,y" << "\n";

    const std::size_t iterations = 2000;
    Space<double, 3, iterations> domain;
    Space<double, 3, iterations> image;

    double power = 400; // watts
    double mass = 70;   // kg
    double c = 0.5;     // drag coeficient
    double a = 0.33;    // frontal area - m^2
    double ro = 1.22;   // air density - kg/m^3

    double dt = 0.1;
    domain[0] = Vector<double, 3>({0, 0, 0});
    image[0] = Vector<double, 3>({4, 0, 0}); // m/s - initial condition

    for (int i = 0; i < iterations - 1; i++)
    {
        double t = dt * (i + 1);
        domain[i + 1] = Vector<double, 3>({t, 0, 0});

        for (int i2 = 0; i2 < 3; i2++)
        {
            if (image[i][i2] == 0)
                continue;

            double acceleration = power / (image[i][i2] * mass);
            double dragAcceleration = 0.5 * c * ro * a * image[i][i2] * image[i][i2] / mass;

            image[i + 1][i2] = image[i][i2] + acceleration * dt - dragAcceleration * dt;
        }
    }

    VectorField<double, 3, iterations> velocity(domain, image);
    image = velocity.getImage();

    for (int i = 0; i < iterations; i++)
    {
        output_file << domain[i][0] << "," << image[i][0] << "\n";
    }

    output_file.close();

    return 0;
}
