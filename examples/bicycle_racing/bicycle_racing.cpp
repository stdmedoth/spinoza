#include <iostream>
#include <fstream>

#include "VectorField.hpp"
#include "ScalarField.hpp"

#include "Space.hpp"

using linear_algebra::Space;
using linear_algebra::Vector;
using linear_algebra::VectorField;
int main()
{
    std::ofstream output_file("bicycle_racing.dat");
    output_file << "x,y" << "\n";

    const std::size_t iterations = 2000;
    Space<double, 3, iterations> domain;
    Space<double, 3, iterations> image;

    double power = 400; // watts
    double mass = 70;   // kg

    double dt = 0.1;
    domain[0] = Vector<double, 3>({0, 0, 0});
    image[0] = Vector<double, 3>({4, 0, 0}); // m/s - initial condition

    for (int i = 0; i < iterations - 1; i++)
    {
        double t = dt * (i + 1);
        domain[i + 1] = Vector<double, 3>({t, 0, 0});

        Vector<double, 3> acceleration = image[i].reciprocal() * (1 / mass) * power;
        image[i + 1] = image[i] + acceleration * dt;
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
