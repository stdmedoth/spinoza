
#ifndef VECTORINTEGRAL_HPP
#define VECTORINTEGRAL_HPP

#include <array>
#include <cmath>

#include "VectorField.hpp"
#include "Space.hpp"
#include "GeometricObject.hpp"

template <typename T, std::size_t M, std::size_t N>
class VectorIntegral : public VectorField<T, M, N>
{
protected:
    Space<T, M, N> f_image;
    std::array<std::size_t, N> parameterization;
    std::size_t object_len;
    GeometricObject<T, M, N> object;

public:
    VectorIntegral()
    {
    }

    VectorIntegral(VectorField<T, M, N> vector_field, GeometricObject<T, M, N> object)
    {

        this->domain = vector_field.getDomain();
        this->f_image = vector_field.getImage();

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
            for (std::size_t m = 0; m < M; m++)
            {
                double dx = (this->domain[parameterization[i + 1]][m] - this->domain[parameterization[i]][m]);
                this->image[i + 1][m] = this->image[i][m] + this->f_image[i][m] * (dx);
            }
        }
    }
};

#endif
