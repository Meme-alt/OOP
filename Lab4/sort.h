#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdarg>
#include <cstring>
#include <vector>
using namespace std;
class Sort
{
    int* arr;
    int size;
public:
    Sort(int nr, int min, int max);
    Sort(int nr, int a);
    Sort(int list[], int nr);
    Sort(int nr, ...);
    Sort(char* s);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    int partition(int low, int high);
    void QuickSortRecursive(int low, int high);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};


