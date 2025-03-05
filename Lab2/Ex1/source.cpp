#include "NumberList.h"
using namespace std;
int main() {
	NumberList NumbersGoBrr;
	int n;
	int nr[10];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nr[i];
	NumbersGoBrr.Init();
	for(int i=0; i<n; i++)
	  NumbersGoBrr.Add(nr[i]);
	NumbersGoBrr.Sort();
	NumbersGoBrr.Print();
	return 0;
}