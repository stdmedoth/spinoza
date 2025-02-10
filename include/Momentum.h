#ifndef MOMENTUM_H

#define MOMENTUM_H

#include "Vector.hpp"
#include "Velocity.h"

class Momentum : public Vector<double, 3>
{
private:
    Velocity velocity;
    double mass;

public:
    Momentum();

    Momentum(Velocity velocity, double mass);

    Momentum(std::array<double, 3> point, double mass);

    int getMagnitude();
};

#endif