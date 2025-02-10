#ifndef POSITION_H

#define POSITION_H

#include "Vector.hpp"

class Position : public Vector<double, 3>
{
private:
public:
    Position();

    Position(Vector<double, 3> vector);

    Position(std::array<double, 3> data);
};

#endif