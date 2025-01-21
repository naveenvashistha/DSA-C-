#include <bits/stdc++.h>

using namespace std;

bool isPowerOfTwo3(int n);
bool isPowerOfTwo2(int n);
bool isPowerOfTwo1(int n);
bool isPowerOfTwo(int n);

int main()
{
    cout << isPowerOfTwo(70) << endl;
}



//orgasmic
//time: O(1)
//space: O(1)
bool isPowerOfTwo3(int n) {
    if(n <= 0) return false;
    int x = log2(n);
    if(n == 1 << x) return true;
    return false;
}

//orgasmic
//time: O(1)
//space: O(1)
bool isPowerOfTwo(int n) {
    if(n <= 0) return false;
    return n & (n - 1) == 0;
}

//brute
//time: O(n)
//space: O(1)
bool isPowerOfTwo1(int n)
{
    for(int i = 0; i < 31; i++)
    {
        if(1 << i == n) return true;
    }
    return false;
}

//better
//time: O(logn)
//space: O(1)
bool isPowerOfTwo2(int n)
{
    if(n <= 0) return false;
    while(n % 2 == 0)
    {
        n = n / 2;
    }
    return n == 1;
}