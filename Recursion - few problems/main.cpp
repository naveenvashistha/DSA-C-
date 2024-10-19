#include <bits/stdc++.h>

using namespace std;

void printNos1(int n);
void printNos2(int n);
int  sumFirstN(int N);
int factorial(int N);

int main()
{
    int N;
    cin >> N;
    printNos1(N);
	cout << endl;
	printNos2(N);
	cout << endl << sumFirstN(N) << endl;
	cout << factorial(N) << endl;
}

//time - O(n)
//space - O(n)
void printNos1(int N)
{
	//Your code here
	if (N > 1)
		printNos1(N - 1);
	cout << N << " ";
}

//time - O(n)
//space - O(n)
void printNos2(int N)
{
	//Your code here
	cout << N << " ";
	if (N > 1)
		printNos2(N - 1);
}

//time - O(n)
//space - O(n)
int  sumFirstN(int N)
{
	//Your code here
	if (N != 0)
	{
		return N + sumFirstN(N - 1);
	}
	return N;
}

//time - O(n)
//space - O(n)
int factorial(int N)
{
	if (N > 1)
		return N * factorial(N - 1);
	return 1;
}