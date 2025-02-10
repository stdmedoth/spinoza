#ifndef VECTOR_FIELD_HPP
#define VECTOR_FIELD_HPP

#include "Vector.hpp"
#include <array>
#include <iostream>

template <typename T, std::size_t N, std::size_t M>
class VectorField
{
private:
    std::array<Vector<T, N>, M> points;  // Posições dos pontos no espaço
    std::array<Vector<T, N>, M> vectors; // Vetores associados a cada ponto

public:
    VectorField()
    {
        for (std::size_t i = 0; i < M; i++)
        {
            points[i] = Vector<T, N>();  // Inicializa pontos com vetor zero
            vectors[i] = Vector<T, N>(); // Inicializa vetores com vetor zero
        }
    }

    void setPoint(std::size_t i, const Vector<T, N> &p) { points[i] = p; }
    void setVector(std::size_t i, const Vector<T, N> &v) { vectors[i] = v; }

    const Vector<T, N> &getPoint(std::size_t i) const { return points[i]; }
    const Vector<T, N> &getVector(std::size_t i) const { return vectors[i]; }

    friend std::ostream &operator<<(std::ostream &os, const VectorField<T, N, M> &vf)
    {
        os << "{\n";
        for (std::size_t i = 0; i < M; i++)
        {
            os << "  " << vf.points[i] << " -> " << vf.vectors[i] << "\n";
        }
        os << "}";
        return os;
    }
};

#endif
