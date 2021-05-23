#include "minHeap.h"


minHeap::minHeap(int i_size)
{
	arr = new Pair[i_size];
	maxSize = i_size;
	currSize = 0;
	allocated = 1;
}

minHeap::minHeap(Pair* A, int i_size)
{
	int parentIdx = (i_size / 2) -1;

	arr = A;
	allocated = 0;

	for (int i = parentIdx; i > 0; i--)
		FixHeap(i);
}

minHeap::~minHeap()
{
	if (allocated)
		delete[] arr;
	arr = nullptr;
}

int minHeap::parent(int node)
{
	return (node - 1) / 2;
}

int minHeap::Left(int node)
{
	return 2 * node + 1;
}


int minHeap::Right(int node)
{
	return 2 * node + 2;
}
void minHeap::Insert(Pair item)
{
	if (currSize == maxSize)
	{
		cout << "error"<<endl;
		return;
	}

	int i = currSize;
	currSize++;

	while (i > 0 && (arr[parent(i)].priority > item.priority))
	{
		arr[i] = arr[parent(i)];
		i = parent(i);
	}
	arr[i] = item;
}

void minHeap::FixHeap(int node)
{
	int min;
	int left = Left(node);
	int right = Right(node);

	if ((left < currSize) && (arr[left].priority < arr[node].priority))
		min = left;

	else if ((right < currSize) && (arr[right].priority < arr[node].priority))
		min = right;
	else
		min = node;

	if (min != node)
	{
		swap(&arr[node], &arr[min]);
		FixHeap(min);
	}
}

void minHeap::swap(Pair* a, Pair* b)
{
	Pair temp = *a;
	*a = *b;
	*b = temp;
}

void minHeap::swap(double* a, double* b) {
	double temp = *a;
	*a = *b;
	*b = temp;
}

Pair minHeap::DeleteMin() 
{
	if (currSize < 1)
	{
		cout << "error"<<endl;
		exit(-1);
	}
	Pair min = arr[0];
	currSize--;
	arr[0] = arr[currSize];
	FixHeap(0);
	return min;
}

Pair minHeap::Min()
{
	return arr[0];
}

bool minHeap::isEmpty()
{
	return currSize == 0;
}

void minHeap::print()
{
	for (int i = 0; i < currSize; i++)
		cout << arr[i].priority << endl;
}