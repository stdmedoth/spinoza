
#ifndef PARTIALDERIVATIVE_HPP
#define PARTIALDERIVATIVE_HPP

#include "Calculus/ScalarFunction.hpp"
#include "LinearAlgebra/Space.hpp"

namespace calculus
{

    template <typename T, std::size_t M, std::size_t N>
    class PartialDerivative : ScalarFunction<T, M, N>
    {
    protected:
        Space<T, 1, N> f_image;

    public:
        PartialDerivative()
        {
        }

        PartialDerivative(ScalarFunction<T, M, N> function, a, b)
        {
            this->domain = function.getDomain();
            this->f_image = function.getImage();

            this->diferentiate(a, b);
        }

        void diferentiate(double a, double b)
        {
            for (std::size_t i = a; i < b; i++)
            {
                double dy = (this->f_image[i + 1] - this->f_image[i]).magnitude();
                double dx = (this->domain[i + 1] - this->domain[i]).magnitude();
                this->image[i + 1][0] = (dy) / (dx);
            }
        }
    };
};

#endif
