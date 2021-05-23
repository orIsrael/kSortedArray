#include"functions.h"

void read(string i_file, int n, Pair *arr)
{
	ifstream file(i_file);
	if (file.is_open())
	{
		int i;

		for (i = 0; i < n; i++)
		{
			string s_temp;
			getline(file, s_temp);
			arr[i].priority = stod(s_temp);
		}
		file.close();
	}
			else cout << "Unable to open file";
}

int partition(Pair* arr, int start, int size)
{
	int pivot, i, temp;
	pivot = start;
	i = size;

	while (i != pivot)
	{
		if (i < pivot)
		{
			if (arr[i].priority < arr[pivot].priority)
				i++;
			else
			{
				swap(&arr[i].priority, &arr[pivot].priority);
				swap(i, pivot);
				i--;
			}
		}
		else
		{
			if (arr[pivot].priority < arr[i].priority)
				i--;
			else
			{
				swap(&arr[i].priority, &arr[pivot].priority);
				swap(i, pivot);
				i++;

			}
		}
	}
	return pivot;

}



void quickSort(Pair* arr, int left, int right)
{
	int pivot, leftPart;

	pivot = partition(arr, left, right);
	
	leftPart = pivot -1 - left;

	if(leftPart > 0)
		quickSort(arr, left, pivot-1);
	if(right - pivot > 0)
		quickSort(arr, pivot + 1, right);

}

void swap(Pair* a, Pair* b)
{
	Pair temp = *a;
	*a = *b;
	*b = temp;
}

void swap(double* a, double* b) {
	double temp = *a;
	*a = *b;
	*b = temp;
}




void kSortedArray(Pair* arr,int left, int n, int k, minHeap &heap,double *sorted)
{

	if (n < k)
	{
		quickSort(arr, 0, n-1);
	}
	else
	{
		int addition = n % k;
		int ceilArray = ceil((double)n / k);
		int i, j;



		for (i = 0; i < addition; i++)
			kSortedArray(arr + (i * ceilArray), i * ceilArray,  ceilArray, k, heap, sorted);
			

		for (i; i < k; i++)
			kSortedArray(arr + i * n / k + addition, i* n / k + addition, n /k, k, heap, sorted);


		for (i = 0; i < addition; i++)
		{
			for (j = 0; j < ceilArray; j++)
			{
				arr[i * ceilArray + j].numOfArr = i;
				arr[i * ceilArray + j].arrSize = ceilArray;
				arr[i * ceilArray + j].idx = j;
			}
		}
		for (i = addition; i < k; i++)
		{
			for (j = 0; j < n / k; j++)
			{
				arr[i * n / k + j + addition].numOfArr = i;
				arr[i * n / k + j + addition].arrSize = n / k;
				arr[i * n / k + j + addition].idx = j;
			}
		}

		for (i = 0; i < addition * ceilArray; i += ceilArray)
			heap.Insert(arr[i]);
		for (i; i < n; i += n / k)
			heap.Insert(arr[i]);


		Pair min;
		i = 0;
		while(!heap.isEmpty())
			{
				min = heap.DeleteMin();

				sorted[i] = min.priority;

				if (min.idx + 1 < min.arrSize && i < n-1)
					heap.Insert(arr[min.arrIdx + 1]);
				i++;
			}
		for (i = 0; i < n; i++)
			arr[i].priority = sorted[i];
		
		
	}
}

void UI()
{
	int n;
	int k;
	int i, j;
	string i_fName;
	string o_fName;

	cout << "Please enter the number of elements (n) and the number of arrays (k)."<<endl;
	cin >> n >> k;

	int addition = n % k;
	int ceilArray = ceil((double)n / k);

	cout << "Please enter the name of the input file"<<endl;
	cin.get();
	getline(cin, i_fName);

	//cout << "Please enter the name of the output file"<<endl;
	//cin.get();
	//getline(cin, o_fName);

	Pair* arr = new Pair[n];
	
	for (i = 0; i < addition; i++)
	{
		for (j = 0; j < ceilArray; j++)
		{
			arr[i * ceilArray + j].numOfArr = i;
			arr[i * ceilArray + j].arrSize = ceilArray;
			arr[i * ceilArray + j].idx = j;
		}
	}
	for (i = addition; i < k; i++) 
	{
		for (j = 0; j < n / k; j++) 
		{
			arr[i * n / k + j+addition].numOfArr = i;
			arr[i * n/k + j +addition].arrSize = n/k;
			arr[i * n/k + j +addition].idx = j;
		}
	}

	for (i = 0; i < n; i++)
		arr[i].arrIdx = i;

	read(i_fName, n, arr);

	for (i = 0; i < n; i++)
		cout << arr[i].priority<<endl;

	minHeap heap(k);

	double* sorted = new double[n];

	kSortedArray(arr, 0, n, k, heap, sorted);

	for (i = 0; i < n; i++)
		cout << arr[i].idx<< endl;

	for (i = 0; i < n; i++)
		cout << arr[i].priority << endl;

	cout << "----------------------------" << endl;
	for (i = 0; i < n; i++)
		cout<<sorted[i]<<endl;
	cout << "----------------------------" << endl;
}






