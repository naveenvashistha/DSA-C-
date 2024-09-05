#include <bits/stdc++.h>

using namespace std;

void printNos(int n);

int main()
{
    int N;
    cin >> N;
    printNos(N);
}

void printNos(int N)
{
	//Your code here
	if (N > 1)
		printNos(N - 1);
	cout << N << " ";
}
