#include <bits/stdc++.h>

using namespace std;

void bitManipulation(int num, int i);

int main()
{
    bitManipulation(70, 3);
}

//time :O(1)
//space: O(1)
void bitManipulation(int num, int i) {
    // get
    if(num & (1 << i - 1))
        cout << 1 << " ";
    else
        cout << 0 << " ";
    //set
    int n = num | (1 << i - 1);
    cout << n << " ";
    //clear
    n = num & (~(1 << i - 1));
    cout << n;
}