#ifndef FUNCTION_H
#define FUNCTION_H

#include <array>
#include <cmath>
#include "Vector.hpp"

template <typename T, std::size_t M, std::size_t N, std::size_t O>
class Function
{

private:
public:
    std::array<Vector<T, M>, O> domain;
    std::array<Vector<T, N>, O> image;

    Function()
    {
        Vector<T, M> _domain;
        Vector<T, N> _image;

        domain.fill(_domain);
        image.fill(_image);
    }

    Function(std::array<Vector<T, M>, O> domain, std::array<Vector<T, N>, O> image) : domain(domain), image(image)
    {
    }

    Function<T, M, N, O> derivative()
    {
        std::array<Vector<T, M>, O> result_domain{};
        std::array<Vector<T, N>, O> result_image{};

        for (std::size_t m = 0; m < O - 1; m++)
        {
            result_domain[m] = domain[m];
            
            for (std::size_t dim = 0; dim < M; dim++)
            {
                result_image[m + 1][dim] = (image[m + 1][dim] - image[m][dim]) / (domain[m + 1][dim] - domain[m][dim]);
            }
        }

        return Function<T, M, N, O>(result_domain, result_image);
    }

    Function<T, M, M*N, O> integral(std::size_t a, std::size_t b)
    {
        std::array<Vector<T, M>, O> result_domain{};
        std::array<Vector<T, M*N>, O> result_image{};

        for (std::size_t i = a; i < b - 1; i++)
        {
            result_domain[i] = domain[i];

            std::size_t pos = 0;
            for (std::size_t j = 0; j < M; j++)
            {
                for (std::size_t k = 0; k < N; k++)
                {
                    result_image[i + 1][pos] = result_image[i][pos] + image[i][k] * (domain[i + 1][j] - domain[i][j]);
                    pos++; 
                    //std::cout << pos << "\n";
                }
            }
        }
        return Function<T, M, M*N, O>(result_domain, result_image);
    }

    std::array<Vector<T, M>, O> &getDomain()
    {
        return domain;
    }

    std::array<Vector<T, N>, O> &getImage()
    {
        return image;
    }

    void setDomain(std::array<Vector<T, M>, O> &domain)
    {
        domain(domain);
    }

    void setImage(std::array<Vector<T, N>, O> &image)
    {
        image(image);
    }

    Function operator+(Function &other)
    {
        std::array<Vector<T, M>, O> result_image{};
        std::array<Vector<T, N>, O> other_image = other.getImage();

        other_image = other.getImage();
        for (std::size_t a = 0; a < O; a++)
        {
            for (std::size_t d = 0; d < M; d++)
            {
                result_image[a][d] = image[a][d] + other_image[a][d];
            }
        }

        return Function(domain, result_image);
    }

    Function operator+(Vector<T, N> vector)
    {
        std::array<Vector<T, N>, O> result_image{};

        for (std::size_t a = 0; a < O; a++)
        {
            for (std::size_t d = 0; d < N; d++)
            {
                result_image[a][d] = image[a][d] + vector[d];
            }
        }

        return Function(domain, result_image);
    }

    Function &operator+=(Function &other)
    {
        std::array<Vector<T, N>, O> other_image = other.getImage();

        other_image = other.getImage();
        for (std::size_t a = 0; a < O; a++)
        {
            for (std::size_t d = 0; d < N; d++)
            {
                image[a][d] += other_image[a][d];
            }
        }

        return *this;
    }

    Function &operator+=(Vector<T, N> &vector)
    {
        for (std::size_t a = 0; a < O; a++)
        {
            image[a] += vector;
        }

        return *this;
    }

    Function &operator=(Vector<T, N> other)
    {
        for (std::size_t a = 0; a < O; a++)
        {
            image[a] = other;
        }

        return *this;
    }

    Function operator-(Function &other)
    {
        std::array<Vector<T, M>, O> result_image{};
        std::array<Vector<T, N>, O> other_image = other.getImage();

        other_image = other.getImage();
        for (std::size_t a = 0; a < O; a++)
        {
            for (std::size_t d = 0; d < N; d++)
            {
                result_image[a][d] = image[a][d] - other_image[a][d];
            }
        }

        return Function(domain, result_image);
    }

    Function operator*(Function &other)
    {
        std::array<Vector<T, M>, O> result_image{};
        std::array<Vector<T, N>, O> other_image = other.getImage();

        for (std::size_t a = 0; a < O; a++)
        {
            for (std::size_t d = 0; d < N; d++)
            {
                result_image[a][d] = image[a][d] * other_image[a][d];
            }
        }

        return Function(domain, result_image);
    }

    Vector<T, N> &operator[](std::size_t index)
    {
        return image[index];
    }
};

#endif
