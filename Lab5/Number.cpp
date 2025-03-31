#include "Number.h"
Number::Number() {
}
Number::Number(const char* value1, int base) {
	v = value1;
	this->base = base;
}
Number::Number(int a) {
	base = 10;
	v = to_string(a);
	value = a;
}
Number::~Number() {
}
int Number::Convert() const {
	int value = 0;
	int p = 1;
	for (int i = v.size() - 1;i >= 0;i--) {
		char cifra = v[i];
		int nr;
		if (cifra >= '0' && cifra <= '9') {
			nr = cifra - '0';
		}
		else if (cifra >= 'A' && cifra <= 'F') {
			nr = cifra - 'A' + 10;
		}
		else if (cifra >= 'a' && cifra <= 'f') {
			nr = cifra - 'a' + 10;
		}
		value += nr * p;
		p = p * base;
	}
	return value;
}
string Number::ConvertBack() {
	char cifra;
	if (base < 2) 
		return "0";
	int value2 = value;
	if (value2 < 0)
		value2 = -value2;
	string result;
	if (value2 == 0)
		return "0";
	while (value2 > 0) {
		int c = value2 % base;
		if (c < 10)
			cifra = c + '0';
		else
			cifra = c + 'A' - 10;
		result = cifra + result;
		value2 = value2 / base;
	}
	if (value < 0) 
		result = "-" + result;
	return result;
}
Number operator+(const Number& i, const Number& j) {
	int a = i.Convert();
	int b = j.Convert();
	Number result;
	result.value = a + b;
	if (i.base > j.base)
		result.base = i.base;
	else
		result.base = j.base;
	result.v = result.ConvertBack();
	return result;
}
Number operator-(const Number& i, const Number& j) {
	int a = i.Convert();
	int b = j.Convert();
	Number result;
	result.value = a - b;
	if (i.base > j.base)
		result.base = i.base;
	else
		result.base = j.base;
	result.v = result.ConvertBack();
	return result;
}
char Number::operator[](int index) {
	return v[index];
}
bool Number::operator>(const Number& i) {
	int a = this->Convert();
	int b = i.Convert();
	if (a > b)
		return true;
	else
		return false;
}
bool Number::operator<(const Number& i) {
	int a = this->Convert();
	int b = i.Convert();
	if (a < b)
		return true;
	else
		return false;
}
bool Number::operator>=(const Number& i) {
	int a = this->Convert();
	int b = i.Convert();
	if (a >= b)
		return true;
	else
		return false;
}
bool Number::operator<=(const Number& i) {
	int a = this->Convert();
	int b = i.Convert();
	if (a <= b)
		return true;
	else
		return false;
}
bool Number::operator==(const Number& i) {
	int a = this->Convert();
	int b = i.Convert();
	if (a == b)
		return true;
	else
		return false;
}
bool Number::operator!=(const Number& i) {
	int a = this->Convert();
	int b = i.Convert();
	if (a != b)
		return true;
	else
		return false;
}
void Number::operator=(string i) {
	v = i;
	if (base == 0)
		base = 10;
}
void Number::operator=(int i) {
	if (base == 0)
		base = 10;
	value = i;
	v = to_string(i);
}
Number::Number(const Number& i) {
	v = i.v;
	base = i.base;
}
void Number::operator+=(const Number& i) {
	int a = this->Convert();
	int b = i.Convert();
	this->value = a + b;
	this->v = this->ConvertBack();
	if (this->base < i.base)
		this->base = i.base;
}
Number::Number(const Number&& i) {
	v = i.v;
	base = i.base;
}
void Number::operator--() {
	v.erase(0, 1);
}
void Number::operator--(int) {
	v.erase(v.size() - 1, 1);
}
void Number::SwitchBase(int newBase) {
	base = newBase;
}
void Number::Print() const {
	cout << v << " ";
}
int Number::GetDigitsCount() {
	int i = v.size();
	return i;
}
int Number::GetBase() const {
	return base;
}
const string& Number::GetString() const {
	return v;
}
Number& Number::operator=(const Number& other) {
	if (this != &other) {
		this->v = other.GetString();
		this->base = other.GetBase();
		this->value = other.Convert();
	}
	return *this;
}