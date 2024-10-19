#include <bits/stdc++.h>

using namespace std;

void frequencyCount(int arr[], int N, int P);

int main()
{
	int N, P;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cin >> P;
	frequencyCount(arr, N, P);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i];
	}
}

//https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0
//time complexity - O(n)
//space complexity - O(n)
void frequencyCount(int arr[], int N, int P) {
	int temp[N];
	for(int i = 0; i < N; i++)
	{
		temp[i] = arr[i];
		arr[i] = 0;
	}
	for(int j = 0; j < N; j++)
	{
		if (temp[j] >= 1 && temp[j] <= N)
			arr[temp[j] - 1] += 1; 
	}
}

