#include "Math.h"
using namespace std;
int main() {
	cout << "Introdu 4 valori int:" << endl;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << endl << "Introdu 3 valori double:" << endl;
	double x, y, z;
	cin >> x >> y >> z;
	cout << "Introdu 2 stringuri:" << endl;
	string s1, s2;
	cin >> s1;
	cin >> s2;
	Math nr;
	cout << nr.Add(a, b) << " " << nr.Add(a, b, c) << " " << nr.Add(x, y) << " " << nr.Add(x, y, z) << endl;
	cout << nr.Mul(a, b) << " " << nr.Mul(a, b, c) << " " << nr.Mul(x, y) << " " << nr.Mul(x, y, z) << endl;
	cout << nr.Add(4, a, b, c, d) << endl;
	cout << nr.Add(s1.c_str(), s2.c_str()) << endl;
	return 0;
}
