#include <bits/stdc++.h>

using namespace std;

void printNos1(int n);
void printNos2(int n);

int main()
{
    int N;
    cin >> N;
    printNos1(N);
	cout << endl;
	printNos2(N);
}

void printNos1(int N)
{
	//Your code here
	if (N > 1)
		printNos1(N - 1);
	cout << N << " ";
}

void printNos2(int N)
{
	//Your code here
	cout << N << " ";
	if (N > 1)
		printNos2(N - 1);
}
