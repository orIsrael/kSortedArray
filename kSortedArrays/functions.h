#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "minHeap.h"
#include <fstream>
#include <string>
#include <chrono>
#include <cmath>

void read(string i_file, int n, Pair* arr);
int partition(Pair* arr, int start, int size);
void quickSort(Pair* arr, int left, int right);
void kSortedArray(Pair* arr,int left, int n, int k, minHeap &heap,double *sorted);
void UI();
bool isNumber(string s);
bool isDigit(char ch);


void swap(Pair* a, Pair* b);
void swap(double* a, double* b);

#endif // !_FUNCTIONS_H
