#include "sort.h"
Sort::Sort(int nr, int min, int max) {
	arr = new int[nr];
	size = nr;
	for (int i = 0; i < nr; i++) {
	int a = min + rand() % (max - min + 1);
	arr[i] = a;
	}
}
Sort::Sort(int nr, int a = 0):size(nr), arr(new int[nr]) {
	for (int i = 0; i < nr; i++)
		cin >> arr[i];
}
Sort::Sort(int list[], int nr) {
	size = nr;
	arr = new int[nr];
	for (int i = 0; i < nr; i++) {
		arr[i] = list[i];
	}
}
Sort::Sort(int nr, ...) {
	size = nr;
	va_list args;
	va_start(args, nr);
	for (int i = 0;i < nr;i++)
		arr[i] = va_arg(args, int);
}
Sort::Sort(char* s) {
	size = 0;

	char* b = new char[strlen(s) + 1];
	strcpy(b, s);
	char* a = strtok(b, ",");
	while (a != nullptr) {
		size++;
		a = strtok(nullptr, ",");
	}
	arr = new int[size];
	strcpy(b, s);
	a = strtok(b, ",");
	int i = 0;
	while (a != nullptr) {
		arr[i] = atoi(a);
		a = strtok(nullptr, ",");
		i++;
	}
	delete[] b;
}
void Sort::InsertSort(bool ascendent) {
	if (ascendent) {
		for (int i = 0; i < size; i++) {
			int key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
	}
	else
		for (int i = 0; i < size; i++) {
			int key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] < key) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
}
int Sort::partition(int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}

void Sort::QuickSortRecursive(int low, int high) {
	if (low < high) {
		int pi = partition(low, high);
		QuickSortRecursive(low, pi - 1);
		QuickSortRecursive(pi + 1, high);
	}
}

void Sort::QuickSort(bool ascendent) {
	QuickSortRecursive(0, size - 1);
	if (!ascendent) {
		int* rev = new int[size];
		for (int i = 0; i < size; i++)
			rev[i] = arr[size - i - 1];
		for (int i = 0; i < size; i++)
			arr[i] = rev[i];
		delete[] rev;
	}
}
void Sort::BubbleSort(bool ascendent) {
	if (ascendent) {
		for (int i = 0;i < size;i++)
			for (int j = 0;j < size;j++)
				if (arr[j] < arr[j + 1])
					swap(arr[j], arr[j + 1]);
	}
	else
		for (int i = 0;i < size;i++)
			for (int j = 0;j < size;j++)
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);			
}
void Sort::Print() {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}
int Sort::GetElementsCount() {
	return size;
}
int Sort::GetElementFromIndex(int index) {
	return arr[index];
}


