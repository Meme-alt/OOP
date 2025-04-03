#pragma once
#include "car.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"
#include <vector>
class Circuit
{
	weather a;
	double speed;
	double length;
	vector<car*> cars;
	vector<car*> failed;
	vector<double> time;
public:
	void SetWeather(weather b);
	void SetLength(double i);
	void AddCar(car* newcar);
	~Circuit();
	void Race();
	void ShowWhoDidNotFinish();
	void ShowFinalRanks();
};

