#include <iostream>

#include "Function.hpp"

int main()
{
        std::array<Vector<double, 3>, 10000> domain;
        std::array<Vector<double, 3>, 10000> image;

        for (int i = 0; i < 10000; i++)
        {
                domain[i] = Vector<double, 3>({0, 0.001 * i, 0});
                image[i] = Vector<double, 3>({0, 10, 0});
        }
        Function<double, 3, 10000> acceleration(domain, image);
        Function<double, 3, 10000> velocity = acceleration.integral(0, 10000);
        Function<double, 3, 10000> position = velocity.integral(0, 10000);

        // Here we have the position calculation for acceleration a = 10
        image = position.getImage();
        for (int i = 0; i < 10000; i++)
        {
                std::cout << image[i] << "\n";
        }

        Function<double, 3, 10000> velocity2 = position.derivative();
        Function<double, 3, 10000> acceleration2 = velocity2.derivative();

        // Here we have the acceleration calculation for last position calculated and should be near of a = 10
        image = acceleration2.getImage();
        for (int i = 0; i < 10000; i++)
        {

                std::cout << image[i] << "\n";
        }

        return 0;
}
