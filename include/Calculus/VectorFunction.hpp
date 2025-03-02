#ifndef VECTORFUNCTION_HPP
#define VECTORFUNCTION_HPP

#include <array>
#include <cmath>
#include "LinearAlgebra/Space.hpp"

namespace calculus
{
    template <typename T, std::size_t M, std::size_t N>
    class VectorFunction
    {

    protected:
        Space<T, M, N> domain;
        Space<T, M, N> image;

    public:
        VectorFunction()
        {
            this->domain = Space<T, M, N>();
            this->image = Space<T, M, N>();
        }

        VectorFunction(const Space<T, M, N> &domain, const Space<T, M, N> &image)
        {
            this->domain = domain;
            this->image = image;
        }

        Space<T, M, N> &getDomain()
        {
            return this->domain;
        }

        Space<T, M, N> &getImage()
        {
            return this->image;
        }

        void setDomain(Space<T, M, N> &domain)
        {
            this->domain = domain;
        }

        void setImage(Space<T, M, N> &image)
        {
            this->image = image;
        }

        VectorFunction operator+(VectorFunction &other)
        {
            Space<T, M, N> result_image{};
            Space<T, M, N> other_image = other.getImage();

            for (std::size_t a = 0; a < N; a++)
            {
                for (std::size_t d = 0; d < M; d++)
                {
                    result_image[a][d] = this->image[a][d] + other_image[a][d];
                }
            }

            return VectorFunction(result_image);
        }

        VectorFunction operator+(Vector<T, M> vector)
        {
            Space<T, M, N> result_domain{};
            Space<T, M, N> result_image{};

            for (std::size_t a = 0; a < N; a++)
            {
                result_domain[a] = this->domain[a];
                for (std::size_t d = 0; d < M; d++)
                {
                    result_image[a][d] = this->image[a][d] + vector[d];
                }
            }

            return VectorFunction(this->domain, result_image);
        }

        VectorFunction &operator+=(VectorFunction &other)
        {
            Space<T, M, N> result_domain{};
            Space<T, M, N> other_image = other.getImage();

            for (std::size_t a = 0; a < N; a++)
            {
                result_domain[a] = this->domain[a];
                for (std::size_t d = 0; d < M; d++)
                {
                    this->image[a][d] += other_image[a][d];
                }
            }

            return *this;
        }

        VectorFunction &operator=(Vector<T, N> other)
        {
            for (std::size_t a = 0; a < N; a++)
            {
                this->image[a] = other;
            }

            return *this;
        }

        VectorFunction operator-(VectorFunction &other)
        {
            Space<T, M, N> result_domain{};
            Space<T, M, N> result_image{};
            Space<T, M, N> other_image = other.getImage();

            for (std::size_t a = 0; a < N; a++)
            {
                result_domain[a] = this->domain[a];
                for (std::size_t d = 0; d < M; d++)
                {
                    result_image[a] = this->image[a] - other_image[a];
                }
            }

            return VectorFunction(this->domain, result_image);
        }

        VectorFunction operator*(VectorFunction &other)
        {
            Space<T, M, N> result_domain{};
            Space<T, M, N> result_image{};
            Space<T, M, N> other_image = other.getImage();

            for (std::size_t a = 0; a < N; a++)
            {
                result_domain[a] = this->domain[a];
                for (std::size_t d = 0; d < M; d++)
                {
                    result_image[a][d] = this->image[a][d] * other_image[a][d];
                }
            }

            return VectorFunction(this->domain, result_image);
        }

        VectorFunction operator*(double &other)
        {
            Space<T, M, N> result_domain{};
            Space<T, M, N> result_image{};

            for (std::size_t a = 0; a < N; a++)
            {
                result_domain[a] = this->domain[a];
                for (std::size_t d = 0; d < M; d++)
                {
                    result_image[a][d] = this->image[a][d] * other;
                }
            }

            return VectorFunction(this->domain, result_image);
        }

        Vector<T, N> &operator[](std::size_t index)
        {
            return image[index];
        }
    };
};

#endif
