#include <bits/stdc++.h>

using namespace std;

void selection(int arr[], int N);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void merge(int arr[], int low, int high);
void quick(int arr[], int low, int high);
void recursive_bubble_sort(int arr[], int end);
void recursive_insertion_sort(int arr[], int end, int N);
void sort_arr(int arr[], int low, int high);
void swap(int arr[], int i, int j);
void printArray(int ar[], int N);

int main()
{
    int N, arr[N];
	cin >> N;
    for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
    //selection(arr, N);
	//bubbleSort(arr, N);
	//insertionSort(arr, N);
	//merge(arr, 0, N - 1);
	//quick(arr, 0, N - 1);
	//recursive_bubble_sort(arr, N - 1);
	recursive_insertion_sort(arr, 1, N);
	printArray(arr, N);
}

//time - O(n^2)
//space - O(1)
void selection(int arr[], int N)
{
	//Your code here
	for (int i = 0; i < N - 1; i++)
	{
		int small = i;
		for (int j = i + 1; j < N; j++)
		{
			if (arr[small] > arr[j])
				small = j;
		}
		if (small != i)
		{
			int temp = arr[i];
			arr[i] = arr[small];
			arr[small] = temp;
		}
	}
}

//time - O(n^2) & omega(n)
//space - O(1)
void bubbleSort(int arr[], int n) {
	// Your code here
	for (int i = 0; i < n - 1; i++)
	{
		int found = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				found = 1;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (found == 0)
			break;
	}
}

//time - O(n^2) & omega(n)
//space - O(1)
void insertionSort(int arr[], int n)
{
	//code here
	for (int i = 1; i < n; i++)
	{
		int j = i;
		while(arr[j] < arr[j - 1] && j > 0)
		{
			int temp = arr[j];
        	arr[j] = arr[j - 1];
        	arr[j - 1] = temp;
			j = j - 1;
		}
	}
}

//time: theta(nlogn)
//space: O(n)
void merge(int arr[], int low, int high)
{
	int mid = (low + high) / 2;
	if (low != high)
	{
		merge(arr, low, mid);
		merge(arr, mid + 1, high);
		sort_arr(arr, low, high);
	}
}

void sort_arr(int arr[], int low, int high)
{
	int temp[high - low + 1];
	int mid = (low + high) / 2;
	int i = low;
	int j = mid + 1;
	int k = 0;
	while(k < high - low + 1)
	{
		if(i > mid)
		{
			temp[k] = arr[j];
			j++;
		}
		else if(j > high)
		{
			temp[k] = arr[i];
			i++;
		}
		else if(arr[i] <= arr[j])
		{
			temp[k] = arr[i];
			i++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	for(int l = low, m = 0; m < high - low + 1 && l <= high; l++, m++)
	{
		arr[l] = temp[m];
	}
}

//time: avg case O(nlogn) and worst case(already sorted): O(n^2)
//space: O(1)
void quick(int arr[], int low, int high)
{
	int pivot = low;
	int length = high;
	while(low <= high)
	{
		if(arr[pivot] < arr[low] && arr[pivot] > arr[high])
		{
			swap(arr, low, high);
			low++;
			high--;
		}
		if(arr[low] <= arr[pivot])
		{
			low++;
		}
		if(arr[high] >= arr[pivot])
		{
			high--;
		}
	}
	swap(arr, high, pivot);
	if (pivot < high - 1)
		quick(arr, pivot, high - 1);
	if (high + 1 < length)
		quick(arr, high + 1, length);
}

//time: best & avg case O(n) , worst case O(n^2)
//space: O(n) auxillary stack space  
void recursive_bubble_sort(int arr[], int end)
{
	int swapped = 0;
	for(int i = 0; i < end; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			swap(arr[i], arr[i + 1]);
			swapped = 1;
		}
	}
	if (swapped == 0 || end - 1 <= 0)
		return;
	else
		recursive_bubble_sort(arr, end - 1);
}

//time: best & avg case O(n) , worst case O(n^2)
//space: O(n) auxillary stack space  
void recursive_insertion_sort(int arr[], int end, int N)
{
	if (end > N - 1)
		return;
	int i = end;
	while(i >= 1 && arr[i - 1] > arr[i])
	{
		swap(arr[i - 1], arr[i]);
		i--;
	}
	recursive_insertion_sort(arr, end + 1, N);
}

void swap(int arr[], int i, int j)
{
	if(i != j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void printArray(int ar[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << ar[i] << " ";
	}
}

