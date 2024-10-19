#include <bits/stdc++.h>

using namespace std;

bool checkArmstrong(int n);

int main()
{
    int N;
    cin >> N;
    cout << checkArmstrong(N) << endl; 
}

//time complexity - O(logn)
//space complexity - O(1)
bool checkArmstrong(int n){
	//Write your code here
	int digits = log10(n) + 1;
	int temp = n;
	int sum = 0;
	while (n != 0)
	{
		sum += pow(n % 10, digits);
		n = n / 10;
	}
	if (sum == temp) return true;
	return false; 
}
