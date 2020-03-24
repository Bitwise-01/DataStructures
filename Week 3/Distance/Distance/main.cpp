#include <iostream>
constexpr double acceleration_due_to_gravity = 9.81;

double fallingDistance(double time);
double fallingVelocity(double time);

int main() {

	double distane;
	double velocity;

	for (double time = 1; time <= 10; time++) {

		distane = fallingDistance(time);
		velocity = fallingVelocity(time);

		std::cout << "Time: " << time << "(s); "
			<< "Distance: " << distane << "(m); "
			<< "Velocity: " << velocity << "(m/s)"
			<< std::endl;
	}

	system("pause");
	return 0;
}

double fallingDistance(double time) {
	return (1.0 / 2.0) * acceleration_due_to_gravity * (time * time);
}

double fallingVelocity(double time) {
	return acceleration_due_to_gravity * time;
}