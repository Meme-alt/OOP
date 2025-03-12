#include "Math.h"
int Math::Add(int a, int b) {
	return a + b;
}
int Math::Add(int a, int b, int c) {
	return a + b + c;
}
int Math::Add(double a, double b) {
	return a + b;
}
int Math::Add(double a, double b, double c) {
	return a + b + c;
}
int Math::Mul(int a, int b) {
	return a * b;
}
int Math::Mul(int a, int b, int c) {
	return a * b * c;
}
int Math::Mul(double a, double b) {
	return a * b;
}
int Math::Mul(double a, double b, double c) {
	return a * b * c;
}
int Math::Add(int count, ...) {
	va_list args;
	va_start(args, count);
	int sum = 0;
	for (int i = 0; i < count; i++)
		sum = sum + va_arg(args, int);
	va_end(args);
	return sum;
}
char* Math::Add(const char* a, const char* b) {
	if (a == nullptr || b == nullptr)
		return nullptr;
	size_t len1 = strlen(a);
	size_t len2 = strlen(b);
	char* rez = new char[len1 + len2 + 1];
	strcpy(rez, a);
	strcat(rez, b);
	return rez;
}
