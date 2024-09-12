#include <bits/stdc++.h>

using namespace std;

void frequencyCount(int arr[], int N);

int main()
{
	int N, P;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	frequencyCount(arr, N);
}

//time complexity - O(n)
//space complexity - O(n)
void frequencyCount(int arr[], int N) {
	unordered_map <int, int> m;
	int min_ele, max_ele, max = 0, min = N;
	for (int i = 0; i < N; i++)
	{
		m[arr[i]] += 1;
	}
	for (auto i: m)
	{
		cout << i.first << ": " << i.second << endl;
		//to find max and min freq element
		if (i.second > max)
		{	max = i.second;
			max_ele = i.first;
		}
		if (i.second < min)
		{
			min = i.second;
			min_ele = i.first;
		}
	}
	cout << "Max ele: " << max_ele << endl;
	cout << "Min ele: " << min_ele << endl;
}

