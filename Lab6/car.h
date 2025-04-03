#pragma once
#include "weather.h"
class car {
public:
	virtual double FuelCapacity() const = 0;
	virtual double FuelConsumption() const = 0;
	virtual double AverageSpeed(weather b) const = 0;
	virtual string GetName() const = 0;
	virtual ~car() = default;
};