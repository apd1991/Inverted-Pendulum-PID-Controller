#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H
class PIDController {
private:
    double target_angle;
    double kp;
    double ki;
    double kd;
    double error_integral;
    double last_error;
public:
    PIDController(double target_angle, double kp, double ki, double kd);
    double control(double current_angle, double time_step);
};
#endif // PID_CONTROLLER_H
