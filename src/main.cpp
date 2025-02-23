#include <iostream>

#include "Field.hpp"
#include "VectorField.hpp"
#include "ScalarField.hpp"

#include "VectorSpace.hpp"

int main()
{
        VectorSpace<double, 3, 10000> domain;
        Field<double, 10000> image;

        VectorSpace<double, 3, 10000> vector_image;

        for (int i = 0; i < 10000; i++)
        {
                double x = 0.001 * i;
                double y = 0.002 * i;
                double z = 0.003 * i;
                domain[i] = Vector<double, 3>({x, y, z});
                image[i] = x + y + z;

                vector_image[i] = Vector<double, 3>({x, y, z});
        }
        ScalarField<double, 3, 10000> temperature(domain, image);
        image = temperature.getImage();
        for (int i = 0; i < 10000; i++)
        {
                std::cout << image[i] << "\n";
        }

        VectorField<double, 3, 10000> position(domain, vector_image);
        vector_image = position.getImage();
        for (int i = 0; i < 10000; i++)
        {
                std::cout << vector_image[i] << "\n";
        }

        return 0;
}
