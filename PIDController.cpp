#include "PIDController.h"
PIDController::PIDController(double target_angle, double kp, double ki, double kd)
    : target_angle(target_angle), kp(kp), ki(ki), kd(kd), error_integral(0), last_error(0) {}
double PIDController::control(double current_angle, double time_step) {
    double error = target_angle - current_angle;
    error_integral += error * time_step;
    double error_derivative = (error - last_error) / time_step;
    double control_signal = kp * error + ki * error_integral + kd * error_derivative;
    last_error = error;
    return control_signal;
}
