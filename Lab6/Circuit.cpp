#include "Circuit.h"
void Circuit::SetWeather(weather b) {
	a = b;
}
void Circuit::SetLength(double i) {
	length = i;
}
void Circuit::AddCar(car* newCar) {
	cars.push_back(newCar);
}
Circuit::~Circuit() {
	for (car* car : cars)
		delete car;
}
void Circuit::Race() {
	for (car* car : cars) {
		double x = car->FuelCapacity();
		double y = car->FuelConsumption();
		double speed = car->AverageSpeed(a);
		if (x < y * length)
			failed.push_back(car);
		else {
			time.push_back(length / speed);
		}
	}
}
void Circuit::ShowFinalRanks() {
	vector<double> arr = time;
	for (int i = 0; i < arr.size() - 1;i++)
		for (int j = i + 1;j < arr.size();j++)
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
	for (double t : arr)
		cout << t*60 << " min" << endl;
}
void Circuit::ShowWhoDidNotFinish() {
	for (car* car : failed) {
		cout << car->GetName() << endl;
	}
}	