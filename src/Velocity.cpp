#include "Velocity.h"

Velocity::Velocity() : Vector<double, 3>({0, 0, 0}) {}

Velocity::Velocity(Vector<double, 3> vector) : Vector<double, 3>(vector) {}

Velocity::Velocity(std::array<double, 3> data) : Vector<double, 3>(data) {}
