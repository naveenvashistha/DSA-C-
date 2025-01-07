#include <bits/stdc++.h>

using namespace std;

int nthroot(int n);

int main()
{
    int n = nthroot(36);
    cout << n << endl;
}

//orgasmic
//time: O(logn)
//space: O(1)
int nthroot(int n, int m)
{
    int low = 1, high = m, mid;
    if(m == 1) return 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(pow(mid, n) == m) return mid;
        else if(pow(mid, n) > m) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}