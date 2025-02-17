#include <iostream>

#include "Function.hpp"

int main()
{
        std::array<Vector<double, 1>, 10000> domain;
        std::array<Vector<double, 3>, 10000> image;

        for (int i = 0; i < 10000; i++)
        {
                double t = 0.001 * i;
                domain[i] = Vector<double, 1>({t});
                image[i] = Vector<double, 3>({0, 10, 0});
        }
        Function<double, 1, 3, 10000> acceleration(domain, image);
        
        Function<double,1, 3, 10000> velocity = acceleration.integral(0, 10000);
        Vector<double, 3> v0({0, 10,0});
        velocity += v0;
        
        Function<double, 1, 3, 10000> position = velocity.integral(0, 10000);

        //image = velocity.getImage();
        image = position.getImage();
        for (int i = 0; i < 10000; i++)
        {
                std::cout << image[i] << "\n";
        }


        return 0;
}
