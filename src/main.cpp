#include <iostream>

#include "ScalarField.hpp"
#include "Field.hpp"
#include "VectorSpace.hpp"

int main()
{
        VectorSpace<double, 3, 10000> domain;
        Field<double, 10000> image;

        for (int i = 0; i < 10000; i++)
        {
                double x = 0.001 * i;
                double y = 0.002 * i;
                double z = 0.003 * i;
                domain[i] = Vector<double, 3>({x, y, z});
                image[i] = x + y + z;
        }
        ScalarField<double, 3, 10000> acceleration(domain, image);
        ScalarField<double, 3, 10000> velocity = acceleration.integral(0, 10000);
        image = velocity.getImage();
        image = image + 10.0;
        velocity.setImage(image);

        /*
        image = velocity.getImage();
        for (int i = 0; i < 10000; i++)
        {
                std::cout << image[i] << "\n";
        }
        */

        ScalarField<double, 3, 10000> position = velocity.integral(0, 10000);
        image = position.getImage();
        for (int i = 0; i < 10000; i++)
        {
                std::cout << image[i] << "\n";
        }

        return 0;
}
