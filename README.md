# Inverted_Pendulum

It's a basic Dynamic simulaiton with PID controller code.

I've added <eigen3/Eigen/Dense> instead of <Eigen/Dense> only. Apparently, I have to go I step up in the directory structure. Alternatively, one could "Include" path to Eigen libraries in the compilation process from terminal (i think a bit tedious).

Do not directly compile main.cpp to run the program. First compile the useful .cpp files and link them to main.cpp by (I'm on Ubuntu with g++ compiler):

Inverted_Pendulum$ g++ -c Pendulum.cpp -o Pendulum.o //Compiled file Pendulum.o creation.

Inverted_Pendulum$ g++ -c PIDController.cpp -o PIDController.o //Compiled file PIDController.o creation.

Inverted_Pendulum$ g++ main.cpp Pendulum.o PIDController.o  -o main.o  //Here the last part "-o main" also works. This is where the linking of Pendulum.o and PIDController.o with main.cpp is done. Finally, a compiled top level "main" executable file is created.

Inverted_Pendulum$ ./main.o //Executing the compiled binary file.
