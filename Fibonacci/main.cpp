#include<bits/stdc++.h>
using namespace std;

int fib_1(int n);
int fib_2(int n);

int main()
{
        int n;
        do
        {
                cin >> n;
        }
        while(n < 1 || n > 10000);

        cout << "Using Recursion: " << fib_1(n) << endl;
        cout << "Using Loop: " << fib_2(n) << endl;
        return 0;
}

int fib_1(int n)
{
        if (n == 1 || n == 2)
        {
                return 1;
        }
        return fib_1(n - 1) + fib_1(n - 2);
}

int fib_2(int n)
{
        int arr[n]; 
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == 1)
            {
                arr[i] = 1;
            }
            else
            {
                arr[i] = arr[i - 1] + arr[i - 2];
            }
        }
        return arr[n-1];
}