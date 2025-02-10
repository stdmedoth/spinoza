#include "Vector.hpp"
#include "Velocity.h"
#include "KinectEnergy.h"

KinectEnergy::KinectEnergy() : velocity({0, 0, 0}), mass(0) {}

KinectEnergy::KinectEnergy(Velocity velocity, double mass) : velocity(velocity), mass(mass) {}

KinectEnergy::KinectEnergy(std::array<double, 3> point, double mass) : velocity(point), mass(mass) {}
