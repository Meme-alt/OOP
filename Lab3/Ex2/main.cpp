#include "Canvas.h"
using namespace std;
int main() {
	Canvas canvas(20, 20);
	canvas.DrawCircle(10, 10, 4,'*');
	canvas.Print();
	cout << endl;
	canvas.FillCircle(10, 10, 4, '*');
	canvas.Print();
	canvas.Clear();
	cout << endl;
	canvas.DrawRect(5, 5, 15, 15, '*');
	canvas.Print();
	cout << endl;
	canvas.FillRect(5, 5, 15, 15, '*');
	canvas.Print();
	canvas.Clear();
	cout << endl;
	canvas.SetPoint(5, 5, '*');
	canvas.Print();
	cout << endl;
	canvas.DrawLine(5, 5, 12, 13, '*');
	canvas.Print();
	return 0;
}