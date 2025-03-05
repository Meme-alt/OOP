#include "NumberList.h"
void NumberList::Init() {
	count = 0;
}
bool NumberList::Add(int x) {
	if (count >= 10) {
		return false;
	}
	numbers[count] = x;
	count++;
}
void NumberList::Sort() {
	int a=0;
	for(int i=0; i<count-1; i++)
		for(int j=0; j<count-1; j++)
			if (numbers[j] > numbers[j + 1]) {
				a = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = a;
			}
}
void NumberList::Print() {
	for (int i = 0; i < count; i++)
		printf("%d ", numbers[i]);
	
}



