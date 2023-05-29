#ifndef PENDULUM_H
#define PENDULUM_H
#include <cmath>
class Pendulum {
private:
    double length;
    double mass;
    double angle;
    double angular_velocity;
public:
    Pendulum(double length, double mass, double initial_angle, double initial_velocity);
    void update(double force, double time_step);
    std::pair<double, double> getPosition();
    double getAngle();
};
#endif // PENDULUM_H
