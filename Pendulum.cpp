#include "Pendulum.h"

Pendulum::Pendulum(double length, double mass, double initial_angle, double initial_velocity)
    : length(length), mass(mass), angle(initial_angle), angular_velocity(initial_velocity) {}

void Pendulum::update(double force, double time_step) {
    double gravity = 9.8;
    double damping = 0.1;
    double angular_acceleration = (force - damping * angular_velocity - gravity * sin(angle) / length) / mass;
    angular_velocity += angular_acceleration * time_step;
    angle += angular_velocity * time_step;
}

std::pair<double, double> Pendulum::getPosition() {
    double x = length * sin(angle);
    double y = -length * cos(angle);
    return std::make_pair(x, y);
}

double Pendulum::getAngle() {
    return angle;
}

