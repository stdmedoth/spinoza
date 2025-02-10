#include "Position.h"

Position::Position() : Vector<double, 3>({0, 0, 0}) {}

Position::Position(Vector<double, 3> vector) : Vector<double, 3>(vector) {}

Position::Position(std::array<double, 3> data) : Vector<double, 3>(data) {}
