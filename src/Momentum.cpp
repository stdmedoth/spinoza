#include "Velocity.h"
#include "Vector.hpp"

class Momentum : public Vector<double, 3>
{
private:
    Velocity velocity;
    double mass;

public:
    Momentum() : velocity({0, 0, 0}), mass(0)
    {
        std::array<double, 3> v;
        v[0] = 0;
        v[1] = 0;
        v[2] = 0;
        setPoint(v);
    }

    Momentum(Velocity velocity, double mass) : velocity(velocity), mass(mass)
    {
        setPoint(velocity.getPoint());
    }

    Momentum(std::array<double, 3> point, double mass) : velocity(point), mass(mass)
    {
        setPoint(point);
    }

    int getMagnitude()
    {
        return mass * sqrt(dot());
    }
};
