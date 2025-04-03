#include "Volvo.h"
double Volvo::FuelCapacity() const {
	return 71.1;
}
double Volvo::FuelConsumption() const {
	return 0.09;
}
double Volvo::AverageSpeed(weather b) const {
	switch (b) {
	case weather::Sunny:
		return 100;
	case weather::Rain:
		return 80;
	case weather::Snow:
		return 50;
	}
}
string Volvo::GetName() const {
	return "Volvo";
}