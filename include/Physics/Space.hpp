#ifndef PHYSICS_SPACE_HPP
#define PHYSICS_SPACE_HPP
#include <array>
#include <cmath>

#include "Physics/Body.hpp"

namespace physics
{
    template <std::size_t N>
    class Space
    {
    protected:
        std::array<Body<N>, N> bodies;

    public:
        Space()
        {
            this->bodies.fill(Body<N>());
        }

        void addBody(Body<N> body)
        {
            std::size_t index = 0;
            for (std::size_t i = 0; i < N; i++)
            {
                if (!this->bodies[i].getMass())
                {
                    index = i;
                    break;
                }
            }
            this->bodies[index] = body;
        }

        Body<N> &getBody(std::size_t index)
        {
            return this->bodies[index];
        }

        void removeBody(std::size_t index)
        {
            this->bodies[index] = NULL;
        }
    };
};

#endif
