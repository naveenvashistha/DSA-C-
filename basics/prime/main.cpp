#include <bits/stdc++.h>

using namespace std;

bool isPrime(int N);

int main()
{
    int N;
    cin >> N;
    cout << isPrime(N) << endl; 
}

//time - O(sqrt(n))
//space - O(1)
bool isPrime(int n)
{
	// Write your code here.
    if (n == 1) return false;
	for(int i = 2; i <= (int)sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;		
		}
	}
	return true;
}
