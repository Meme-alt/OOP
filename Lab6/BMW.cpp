#include "BMW.h"
double BMW::FuelCapacity() const {
	return 50;
}
double BMW::FuelConsumption() const {
	return 0.08;
}
double BMW::AverageSpeed(weather b) const {
	switch (b) {
	case weather::Sunny:
		return 130;
	case weather::Rain:
		return 110;
	case weather::Snow:
		return 70;
	}
}
string BMW::GetName() const {
	return "BMW";
}
