#include "tree.h"

bool same(int k, int d) {
	if (k == d) {
		return true;
	}
	return false;
}
float operator"" _Kelvin(unsigned long long x) {
	return (x - 273.15);
}
float operator"" _Fahrenheit(unsigned long long x) {
	return (x - 32) * 5 / 9;
}
int main() {
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;
	return 0;
}