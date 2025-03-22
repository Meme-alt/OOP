#include "sort.h"
int main() {
	int nr, min, max;
	cin >> nr >> min >> max;
	Sort sort1(nr, min, max);
	sort1.Print();
	sort1.InsertSort();
	cout << endl;
	sort1.Print();
	cout << endl;
	int a = 0;
	Sort sort2(nr, a);
	sort2.QuickSort(true);
	sort2.Print();
	cout << endl;
	int list[1000];
	for (int i = 0;i < nr;i++)
		cin >> list[i];
	Sort sort3(list, nr);
	sort3.BubbleSort(true);
	sort3.Print();
	cout << endl;
	const int max_size = 256;
	char s[max_size];
	cin.getline(s, max_size);
	Sort sort4(s);
	sort4.GetElementsCount();
	int index;
	cin >> index;
	sort4.GetElementFromIndex(index);
	sort4.QuickSort();
	sort4.Print();
	return 0;
}