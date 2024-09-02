#include <bits/stdc++.h>

using namespace std;

bool palindrome(int N);

int main()
{
    int N;
    cin >> N;
    cout << palindrome(N) << endl; 
}

bool palindrome(int N){
    if (N < 0) return false;
    if (N < 10) return true;
    int digits = (log10(N) + 1);
    int halfDigit = digits / 2;
    int revNum = 0, lastDigit;
    while (halfDigit != 0)
    {
        lastDigit = N % 10;
        N = N / 10;
        revNum = revNum * 10 + lastDigit;
        halfDigit--;
    }
    if (digits % 2 == 0)
    {
        if (N == revNum) return true;
    }
    else if ((int)(N / 10) == revNum) return true;
    return false;
}