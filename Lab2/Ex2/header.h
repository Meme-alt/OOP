#pragma once
#include <iostream>
#include <string>
using namespace std;
class header
{
	string name;
	float MathGrade;
	float EnglishGrade;
	float HistoryGrade;
public:
	string GetName();
	void SetName(string x);
	float GetMathGrade();
	void SetMathGrade(float x);
	float GetEnglishGrade();
	void SetEnglishGrade(float x);
	float GetHistoryGrade();
	void SetHistoryGrade(float x);
	float GetAverageGrade();
};

