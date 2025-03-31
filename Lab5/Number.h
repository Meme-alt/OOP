#pragma once
#include <iostream>
#include <string>
using namespace std;
class Number
{
	string v;
	int base = 0;
	int value;
public:
	Number& operator=(const Number& other);
	Number();
	Number(const char* value1, int base); // where base is between 2 and 16
	Number(int a);
	~Number();
	int Convert() const;
	string ConvertBack();
	const string& GetString() const;
	friend Number operator+ (const Number& i, const Number& j);
	friend Number operator- (const Number& i, const Number& j);
	char operator[](int index);
	bool operator>(const Number& i);
	bool operator<(const Number& i);
	bool operator>=(const Number& i);
	bool operator<=(const Number& i);
	bool operator==(const Number& i);
	bool operator!=(const Number& i);
	void operator=(string i);
	void operator=(int i);
	void operator+=(const Number& i);
	Number(const Number& i);
	Number(const Number&& i);
	void operator--();
	void operator--(int);
	// add operators and copy/move constructor

	void SwitchBase(int newBase);
	void Print() const;
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase() const; // returns the current base
};
