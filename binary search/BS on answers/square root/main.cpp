#include <bits/stdc++.h>

using namespace std;

int square_root(int n);

int main()
{
    int n = square_root(36);
    cout << n << endl;
}

//orgasmic
//time: O(logn)
//space: O(1)
int square_root(int n)
{
    int low = 1, high = n / 2, mid;
    int ans = 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(mid * mid == n) return n;
        else if(mid * mid > n) high = mid - 1;
        else{
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}