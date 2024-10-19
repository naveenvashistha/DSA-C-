#include <bits/stdc++.h>

using namespace std;

int reverse(int x);

int main()
{
    int N;
    cin >> N;
    cout << reverse(N) << endl; 
}

//time - O(logn)
//space - O(1)
int reverse(int x) {
    int lastDigit;
    long long revNum = 0;
    while (x != 0)
    {
        lastDigit = x % 10;
        x = x / 10;
        revNum = revNum * 10 + lastDigit;
        if (revNum > INT32_MAX || revNum < INT32_MIN)
        {
            return 0;
        }
    }
    return revNum;
}