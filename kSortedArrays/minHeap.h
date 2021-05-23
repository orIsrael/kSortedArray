#ifndef _MIN_HEAP
#define _MIN_HEAP
#include <iostream>
using namespace std;

	typedef struct
	{
		double priority;
		int numOfArr;
		int idx;
		int arrSize;
		int arrIdx;
	}Pair;

	class minHeap
	{
		Pair* arr;
		int maxSize;
		int currSize;
		int allocated; //1 if heap allocated memory
		static int Left(int node);
		static int Right(int node);
		static int parent(int node);
		void FixHeap(int node);
	public:
		minHeap(int size);
		minHeap(Pair* A, int n); // build heap from an arrey of n elements
		~minHeap();
		Pair Min();
		Pair DeleteMin();
		void Insert(Pair Item);
		void swap(Pair* a, Pair* b);
		void swap(double* a, double* b);
		bool isEmpty();
		void print();
	};

#endif // _MIN_HEAP