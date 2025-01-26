#include <bits/stdc++.h>

using namespace std;

void print_divisors(int n);

int main()
{
    print_divisors(20);
}

//orgasmic
//time: O(sqrt(n))
//space: O(1)
void print_divisors(int n) {
    // Code here.
    if(n == 1)
    {
        cout << n << " " << endl;
        return;
    }
    for(int i = 1; i < sqrt(n); i++)
    {
        if(n % i == 0) cout << i << " ";
    }
    for(int i = sqrt(n); i >= 1; i--)
    {
        if(n % (n / i) == 0) cout << n / i << " ";
    }
    cout << endl;
}