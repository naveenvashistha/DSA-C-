#include <bits/stdc++.h>

using namespace std;

int findXOR(int l, int r) ;
int xorr(int m, int rem);

int main()
{
    cout << findXOR(7, 10) << endl;
}

int xorr(int m, int rem)
{
    if(rem == 0) return m;
    else if(rem == 1) return 1;
    else if(rem == 2) return m + 1;
    else return 0;
}

//orgasmic
//time: O(1)
//space: O(1)
int findXOR(int l, int r) {
    // complete the function here
    
    int rem1 = r % 4;
    int rem2 = (l - 1) % 4;
    return xorr(r, rem1) ^ xorr(l - 1, rem2);
}