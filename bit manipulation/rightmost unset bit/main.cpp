#include <bits/stdc++.h>

using namespace std;

int setBit(int n);

int main()
{
    cout << setBit(70) << endl;
}

//time: O(1)
//space: O(1)
int setBit(int n) {
    // Write Your Code here
    return n | (n + 1);
}