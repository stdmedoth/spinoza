#ifndef VELOCITY_H

#define VELOCITY_H

#include "Vector.hpp"

class Velocity : public Vector<double, 3>
{
private:
public:
    Velocity();

    Velocity(Vector<double, 3> vector);

    Velocity(std::array<double, 3> data);
};

#endif
