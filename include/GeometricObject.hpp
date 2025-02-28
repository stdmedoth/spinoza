
#ifndef GRADIENT_HPP
#define GRADIENT_HPP

#include "Space.hpp"

template <typename T, std::size_t M, std::size_t N>
class GeometricObject
{
protected:
    Space<T, M, N> set;

public:
    GeometricObject()
    {
        this->set = Space<T, M, N>();
    }
    GeometricObject(const Space<T, M, N> &set)
    {
        this->set = set;
    }

    Space<T, M, N> getSet()
    {
        return this->set;
    }

    Vector<T, M> &operator[](std::size_t index)
    {
        return this->set[index];
    }
};

#endif
