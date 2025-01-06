#include <bits/stdc++.h>

using namespace std;

double myPow(double x, int n);

int main()
{
   cout << myPow(2.0, 10) << endl;
}

//brute
//time:O(n)
//space: O(1)
double myPow(double x, int n) {
    long m;
    if(n < 0) m = -(long)n;
    else m = n;
    double ans = 1;
    for(long i = 1; i <= m; i++)
    {
        ans = ans * x;
    }
    if(n < 0) return 1 / ans;
    return ans;
}

//orgasmic (binary exponentiation)
//time: O(logn)
//space: O(1)
double myPow(double x, int n) {
    long nn;
    if(n < 0) nn = -(long)n;
    else nn = n;
    double ans = 1;
    while(nn)
    {
        if(nn % 2)
        {
            ans = ans * x;
            nn = nn - 1;
        }
        else
        {
            x = x * x;
            nn = nn / 2;
        }
    }
    if(n < 0) return 1 / ans;
    return ans;
}