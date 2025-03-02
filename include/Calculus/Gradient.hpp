
#ifndef DERIVATIVE_HPP
#define DERIVATIVE_HPP

#include <array>
#include <cmath>

#include "LinearAlgebra/ScalarField.hpp"
#include "LinearAlgebra/Space.hpp"

namespace calculus
{
    template <typename T, std::size_t M, std::size_t N>
    class Gradient : public VectorField
    {

    protected:
        Space<T, M, N>() f_image;

    public:
        Gradient()
        {
        }

        Gradient(VectorFunction<T, M, N> function, a, b)
        {
            this->domain = function.getDomain();
            this->f_image = function.getImage();

            this->diferentiate(a, b);
        }

        void diferentiate(double a, double b)
        {
            for (std::size_t i = a; i < b; i++)
            {
                for (std::size_t m = 0; m < M; m++)
                {
                    {
                        double dy = this->f_image[i + 1][m] - this->f_image[i][m];
                        double dx = this->domain[i + 1][m] - this->domain[i][m];
                        this->image[i + 1][m] = (dy) / (dx);
                    }
                }
            }
        }
    };
};

#endif
