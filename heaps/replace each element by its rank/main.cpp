#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(nlogn)
//space: O(n)
vector<int> replaceWithRank(vector<int> &arr, int N){
    unordered_map<int, int> mp;
    vector<int> v = arr;
    int rank = 1;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < N; i++)
    {
        mp[arr[i]] = rank;
        if(i != N - 1 && arr[i] != arr[i + 1]) rank++;
    }
    for(int i = 0; i < N; i++)
    {
        v[i] = mp[v[i]];
    }
    return v;
}

int main()
{
}

