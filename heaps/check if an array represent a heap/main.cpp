#include <bits/stdc++.h>

using namespace std;

//time: O(n)
//space: O(1)
bool isMaxHeap(int arr[], int n)
{
    // Your code goes here
    for(int i = 0; i < n; i++)
    {
        if(2 * i + 1 < n && arr[i] < arr[2 * i + 1]) return false;
        if(2 * i + 2 < n && arr[i] < arr[2 * i + 2]) return false;
    }
    return true;
}

int main()
{
}

