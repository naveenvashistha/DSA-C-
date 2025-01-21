#include <bits/stdc++.h>

using namespace std;

int countSetBits3(int n);
int countSetBits2(int n);
int countSetBits1(int n);

int main()
{
    cout << countSetBits1(70) << endl;
}


//brute
//time: O(n * no of bits)
//space: O(1)
int countSetBits1(int n)
{
    // Your logic here
    int count = 0;
    int pos = 0;
    for(int i = 1; i <= n; i++)
    {
        while(1)
        {
            if((1 << pos) > i) break;
            if(i & (1 << pos)) count++;
            pos++;
        }
    }
    return count;
}

//better
//time: O(no of set bits * n)
//space: O(1)
int countSetBits2(int n)
{
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        int n = i;
        while(n != 0)
        {
            n = n & (n - 1);
            count++;
        }
    }
    return count;
}

//orgasmic
//time: O(logn)
//sspace: O(logn) recursive space
int countSetBits3(int n)
{
    if(n == 0) return 0;
    int x = log2(n);
    int count = 0;
    count += (1 << (x - 1)) * x;
    count += n - (1 << x) + 1;
    return count + countSetBits3(n - (1 << x));
}