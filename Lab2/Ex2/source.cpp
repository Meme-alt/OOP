#include "global.h"
int main() {
	header student1;
	header student2;
	string name1, name2;
	getline(cin, name1);
	getline(cin, name2);
	float Math1, Math2, English1, English2, History1, History2;
	cin >> Math1 >> Math2 >> English1 >> English2 >> History1 >> History2;
	student1.SetName(name1);
	student1.SetMathGrade(Math1);
	student1.SetEnglishGrade(English1);
	student1.SetHistoryGrade(History1);
	student2.SetName(name2);
	student2.SetMathGrade(Math2);
	student2.SetEnglishGrade(English2);
	student2.SetHistoryGrade(History2);
	cout << "student1: " << student1.GetAverageGrade() << endl << "student2: " << student2.GetAverageGrade()<< endl;
	if (CompareName(student1.GetName(), student2.GetName()) == 0)
		cout << "Name: Equal" << endl;
	else
		if (CompareName(student1.GetName(), student2.GetName()) >= 0)
			cout << "Name: " << student1.GetName() << endl;
		else
			cout << "Name: " << student2.GetName() << endl;
	if (CompareMathGrades(student1.GetMathGrade(), student2.GetMathGrade()) == 0)
		cout << "Math Grade: Equal" << endl;
	else
		if (CompareMathGrades(student1.GetMathGrade(), student2.GetMathGrade()) >= 0)
			cout << "Math Grade: " << student1.GetMathGrade() << endl;
		else
			cout << "Math Grade: " << student2.GetMathGrade() << endl;
	if (CompareEnglishGrades(student1.GetEnglishGrade(), student2.GetEnglishGrade()) == 0)
		cout << "English Grade: Equal" << endl;
	else
		if (CompareEnglishGrades(student1.GetEnglishGrade(), student2.GetEnglishGrade()) >= 0)
			cout << "English Grade: " << student1.GetEnglishGrade() << endl;
		else
			cout << "English Grade: " << student2.GetEnglishGrade() << endl;
	if (CompareHistoryGrades(student1.GetHistoryGrade(), student2.GetHistoryGrade()) == 0)
		cout << "History Grade: Equal" << endl;
	else
		if (CompareHistoryGrades(student1.GetHistoryGrade(), student2.GetHistoryGrade()) >= 0)
			cout << "History Grade: " << student1.GetHistoryGrade() << endl;
		else
			cout << "History Grade: " << student2.GetHistoryGrade() << endl;
	if (CompareAverageGrades(student1.GetAverageGrade(), student2.GetAverageGrade()) == 0)
		cout << "Average Grade: Equal" << endl;
	else
		if (CompareAverageGrades(student1.GetAverageGrade(), student2.GetAverageGrade()) >= 0)
			cout << "Average Grade: " << student1.GetAverageGrade() << endl;
		else
			cout << "Average Grade: " << student2.GetAverageGrade() << endl;
	return 0;
}