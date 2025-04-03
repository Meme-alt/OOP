#include "RangeRover.h"
double RangeRover::FuelCapacity() const {
	return 80;
}
double RangeRover::FuelConsumption() const {
	return 0.02;
}
double RangeRover::AverageSpeed(weather b) const {
	switch (b) {
	case weather::Sunny:
		return 60;
	case weather::Rain:
		return 30;
	case weather::Snow:
		return 10;
	}
}
string RangeRover::GetName() const {
	return "RangeRover";
}
