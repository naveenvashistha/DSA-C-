#include <bits/stdc++.h>

using namespace std;

int countGoodNumbers(long long n);
long long myPow(long long x, long long p, long long ans);

int main()
{
    int ss = countGoodNumbers(50);
    cout << ss << endl;
}

long long myPow(long long x, long long p, long long ans)
{
    int mod = 1e9 + 7;
    if(p == 0) return ans;
    if(p % 2 != 0) return myPow(x, --p, (ans * x) % mod);
    else return myPow((x * x) % mod, p / 2, ans); 
}

int countGoodNumbers(long long n) {
    long long odd = n / 2;
    long long even = n - odd;
    int mod = 1e9 + 7;
    long long ans = (myPow(4, odd, 1) * myPow(5, even, 1)) % mod;
    return (int)ans;
}