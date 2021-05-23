#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "minHeap.h"
#include <fstream>
#include <string>
#include <chrono>

void read(string i_file, int n, Pair* arr);
int partition(Pair* arr, int start, int size);
//int Partition(Pair* arr, int low, int high, double pivotValue);
void quickSort(Pair* arr, int left, int right);
void kSortedArray(Pair* arr, int n, int k, minHeap &heap,double *sorted);
void UI();


void swap(Pair* a, Pair* b);
void swap(double* a, double* b);

#endif // !_FUNCTIONS_H
