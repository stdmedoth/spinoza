
#ifndef PATHINTEGRAL_HPP
#define PATHINTEGRAL_HPP

#include <array>
#include <cmath>

#include "ScalarField.hpp"
#include "Space.hpp"
#include "GeometricObject.hpp"

template <typename T, std::size_t M, std::size_t N, std::size_t O>
class ScalarIntegral : public ScalarField
{
protected:
    Space<T, M, N> f_image;
    std::array<T, N> parameterization;

    GeometricObject<T, M, O> object;

public:
    ScalarIntegral()
    {
    }

    ScalarIntegral(ScalarField<T, M, N> function, Path<T, O> path)
    {
        this->domain = function.getDomain();
        this->f_image = function.getImage();
        this->parameterization = this->domain.parametrize(this->object);

        this->integrate();
    }

    void integrate()
    {
        for (std::size_t i = 0; i < N; i++)
        {
            double dx = (this->domain[parameterization[i + 1]] - this->domain[parameterization[i]]).magnitude();
            this->image[i + 1][0] = this->image[i][0] + this->f_image[i][0] * (dx);
        }
    }
};

#endif
