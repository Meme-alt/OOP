#include "Fiat.h"
double Fiat::FuelCapacity() const {
	return 40;
}
double Fiat::FuelConsumption() const {
	return 0.03;
}
double Fiat::AverageSpeed(weather b) const {
	switch (b) {
	case weather::Sunny:
		return 80;
	case weather::Rain:
		return 50;
	case weather::Snow:
		return 30;
	}
}
string Fiat::GetName() const {
	return "Fiat";
}