#include "Seat.h"
double Seat::FuelCapacity() const {
	return 55;
}
double Seat::FuelConsumption() const {
	return 0.05;
}
double Seat::AverageSpeed(weather b) const {
	switch (b) {
	case weather::Sunny:
		return 110;
	case weather::Rain:
		return 80;
	case weather::Snow:
		return 60;
	}
}
string Seat::GetName() const {
	return "Seat";
}
