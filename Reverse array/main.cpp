#include <bits/stdc++.h>

using namespace std;

void reverse1(int N, int ar1[], int ar2[]);
void reverse2(int N, int ar[]);
void reverse3(int i, int j, int ar[]);
void reverse4(int N, int ar[]);
void printArray(int N, int ar[]);

int main()
{
    int N, ar[N], temp[N];
	cin >> N;
    for (int i = 0; i < N; i++)
	{
		cin >> ar[i];
	}
    //reverse1(N, ar, temp);
	//reverse2(N, ar);
	reverse3(0, N - 1, ar);
	printArray(N, ar);
	//reverse4(N, ar);
}

//time - O(n)
//space - O(n)
void reverse1(int N, int ar1[], int ar2[])
{
	//Your code here
	for (int i = 0; i < N; i++)
	{
		ar2[N - i - 1] = ar1[i];
	}
	printArray(N, ar2);
}

//time - O(n)
//space - O(1)
void reverse2(int N, int ar[])
{
	int temp;
	for (int i = 0; i < N/2; i++)
	{
		temp = ar[i];
		ar[i] = ar[N - i - 1];
		ar[N - i - 1] = temp;
	}
	printArray(N, ar);
}

//time - O(n)
//space - O(n)
void reverse3(int i, int j, int ar[])
{
	if (i >= j)
	{
		return;
	}
	int temp = ar[i];
	ar[i] = ar[j];
	ar[j] = temp;
	reverse3(i + 1, j - 1, ar);
}

//time - O(n)
//space - O(1)
void reverse4(int N, int ar[])
{
	reverse(ar, ar + N);
	printArray(N, ar);
}

void printArray(int N, int ar[])
{
	for (int i = 0; i < N; i++)
	{
		cout << ar[i] << " ";
	}
}
