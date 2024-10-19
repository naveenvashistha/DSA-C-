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
        while(n < 0 || n > 10000);

        cout << "Using Recursion: " << fib_1(n) << endl;
        cout << "Using Loop: " << fib_2(n) << endl;
        return 0;
}

//time - O(2^n)
//space - O(n)
int fib_1(int n)
{
        if (n <= 1)
        {
                return n;
        }
        return fib_1(n - 1) + fib_1(n - 2);
}

//time - O(n)
//space - O(1)
int fib_2(int n)
{
        int n1 = 0, n2 = 1;
        int temp;
        if (n <= 1) return n;
        for (int i = 0; i < n - 1; i++)
        {
                temp = n2;
                n2 = n1 + n2;
                n1 = temp;
        }
        return n2;
}

