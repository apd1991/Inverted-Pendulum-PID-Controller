#include <iostream>
#include <fstream>  // Include the header for file stream operations
#include "Pendulum.h"
#include "PIDController.h"

int main() {
    Pendulum pendulum(1.0, 1.0, 0.2, 0.0);
    PIDController pid_controller(90.0, 2.0, 0.5, 1.0);
    double time_step = 0.01;

    std::ofstream outputFile("output.txt");  // Open the file for writing

    if (!outputFile) {
    std::cout << "Failed to open the file." << std::endl;
    return 1;  // Return error code if file opening fails
}

// Write table headers
outputFile << "Time\tAngle\tForce\tPosition\n";
double time=0;
    for (int i = 0; i < 1000; ++i) {
        time += time_step;
        double current_angle = pendulum.getAngle();
        double control_signal = pid_controller.control(current_angle, time_step);
        pendulum.update(control_signal, time_step);
        std::pair<double, double> position = pendulum.getPosition();
        std::cout << "Position: (" << position.first << ", " << position.second << ")" << std::endl;
        std::cout << current_angle << std::endl;


        // Write data in table format
    outputFile << time << "\t" << current_angle << "\t" << control_signal << "\t"
               << position.first << ", " << position.second << "\n";
    }

    outputFile.close();  // Close the file

    std::cout << "Data has been written to output.txt" << std::endl;
    return 0;
}
