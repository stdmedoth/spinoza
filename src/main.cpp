#include <iostream>

#include "VectorField.hpp"
#include "VectorSpace.hpp"

int main()
{
        VectorSpace<double, 3, 10000> domain;
        VectorSpace<double, 3, 10000> image;

        for (int i = 0; i < 10000; i++)
        {
                double t = 0.001 * i;
                domain[i] = Vector<double, 3>({t, t, t});
                image[i] = Vector<double, 3>({0, 10, 0});
        }
        VectorField<double, 3, 10000> acceleration(domain, image);

        VectorField<double, 3, 10000> velocity = acceleration.integral(0, 10000);
        image = velocity.getImage();
        image = image + Vector<double, 3>({10, 0, 0});
        velocity.setImage(image);

        /*
        image = velocity.getImage();
        for (int i = 0; i < 10000; i++)
        {
                std::cout << image[i] << "\n";
        }
        */

        VectorField<double, 3, 10000> position = velocity.integral(0, 10000);
        image = position.getImage();
        for (int i = 0; i < 10000; i++)
        {
                std::cout << image[i] << "\n";
        }

        return 0;
}
