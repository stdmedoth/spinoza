
#ifndef PATHINTEGRAL_HPP
#define PATHINTEGRAL_HPP

#include <array>
#include <cmath>

#include "ScalarField.hpp"
#include "Space.hpp"
#include "GeometricObject.hpp"

template <typename T, std::size_t M, std::size_t N>
class ScalarIntegral : public ScalarField<T, M, N>
{
protected:
    Space<T, M, N> f_image;
    std::array<std::size_t, N> parameterization;
    std::size_t object_len;
    GeometricObject<T, M, N> object;

public:
    ScalarIntegral()
    {
    }

    ScalarIntegral(ScalarField<T, M, N> scalar_field, GeometricObject<T, M, N> object)
    {

        this->domain = scalar_field.getDomain();
        this->f_image = scalar_field.getImage();

        Space<T, M, N> object_space = object.getSet();

        double dx = (this->domain[1] - this->domain[0]).magnitude();
        auto [parameterization, object_len] = this->domain.parametrize(object_space, dx);
        this->parameterization = parameterization;
        this->object_len = object_len;

        this->integrate();
    }

    void integrate()
    {
        for (std::size_t i = 0; i < this->object_len; i++)
        {
            double dx = (this->domain[parameterization[i + 1]] - this->domain[parameterization[i]]).magnitude();
            this->image[i + 1] = this->image[i] + this->f_image[i] * (dx);
        }
    }
};

#endif
