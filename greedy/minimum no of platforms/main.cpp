#include <bits/stdc++.h>

using namespace std;

//time: O(nlogn)
//space: O(1)
int findPlatform(vector<int>& arr, vector<int>& dep) {
    // Your code here
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int j = 0;
    int platforms = 1;
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] <= dep[j]) platforms++;
        else j++;
    }
    return platforms;
}


int main()
{
}

