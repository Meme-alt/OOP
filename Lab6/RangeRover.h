#pragma once
#include "car.h"
class RangeRover : public car
{
	double FuelCapacity() const override;
	double FuelConsumption() const override;
	double AverageSpeed(weather b) const override;
	string GetName() const override;
};

