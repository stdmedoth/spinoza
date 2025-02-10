#ifndef KINECT_ENERGY_H

#define KINECT_ENERGY_H

#include "Vector.hpp"
#include "Velocity.h"

class KinectEnergy
{
private:
    Velocity velocity;
    double mass;

public:
    KinectEnergy();

    KinectEnergy(Velocity velocity, double mass);

    KinectEnergy(std::array<double, 3> point, double mass);
};

#endif