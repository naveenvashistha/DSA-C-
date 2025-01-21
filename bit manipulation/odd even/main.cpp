#include <bits/stdc++.h>

using namespace std;

bool isEven(int n);

int main()
{
    cout << isEven(70) << endl;
}

//time :O(1)
//space: O(1)
bool isEven(int n) {
    // code here
    if(n & 1) return false;
    return true;
}