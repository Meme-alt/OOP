#include "header.h"
string header::GetName()
{
	return name;
}
void header::SetName(string x)
{
	name = x;
}
float header::GetMathGrade() {
	return MathGrade;
}
void header::SetMathGrade(float x) {
	MathGrade = x;
}
float header::GetEnglishGrade() {
	return EnglishGrade;
}
void header::SetEnglishGrade(float x) {
	EnglishGrade = x;
}
float header::GetHistoryGrade() {
	return HistoryGrade;
}
void header::SetHistoryGrade(float x) {
	HistoryGrade = x;
}
float header::GetAverageGrade() {
	return (MathGrade + EnglishGrade + HistoryGrade) / 3;
}


