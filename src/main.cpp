#include <iostream>

#include "Surface.hpp"
#include "VectorField.hpp"

#include "VectorIntegral.hpp"

#include "Vector.hpp"

#include <math.h>

int main()
{
        double pi = 3.14159265358979311600;
        Surface<double, 1000> surface;

        for (int i = 0; i < pi * 100; i++)
        {
                surface[i] = Vector<double, 2>({2 * sin(i), 2 * cos(i)});
        }

        VectorField<double, 2, 1000> vf;
        Space<double, 2, 1000> domain;
        Space<double, 2, 1000> image;
        for (int i = 0; i < 1000; i++)
        {
                domain[i] = Vector<double, 2>({2 * sin(i), 2 * cos(i)});
                image[i] = Vector<double, 2>({1.0, 1.0});
        }
        vf.setDomain(domain);
        vf.setImage(image);

        VectorIntegral<double, 2, 1000> vi(vf, surface);

        domain = vi.getDomain();
        image = vi.getImage();
        for (int i = 0; i < 1000; i++)
        {
                std::cout << domain[i] << " : " << image[i] << "\n";
        }

        return 0;
}
