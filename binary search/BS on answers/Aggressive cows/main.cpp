#include <bits/stdc++.h>

using namespace std;

int cows1(vector<int>& stalls, int k);
int cows2(vector<int>& stalls, int k);
bool isPlacementPossible(vector<int>& arr, int k, int min_dist, int size);

int main()
{
    vector<int> nums = {2,3,4,7,11};
    int n = cows1(nums, 5);
    cout << n << endl;
}

//brute
//time: O(n * (maxx dist))
//space: O(1)
int cows1(vector<int>& stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    for(int i = stalls[n - 1] - stalls[0]; i >= 1; i--)
    {
        bool res = isPlacementPossible(stalls, k, i, n);
        if(res == true)
            return i;
    }
    return -1;
}

//orgasmic
//time: O(n * log(max dist between two stalls))
//sapce: O(1)
int cows2(vector<int>& stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int dist = INT_MIN;
    int low = 1, high = stalls[n - 1] - stalls[0], mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        bool res = isPlacementPossible(stalls, k, mid, n);
        if(res == true)
        {
            dist = max(dist, mid);
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return dist;
}

bool isPlacementPossible(vector<int>& stalls, int k, int min_dist, int size)
{
    int current = 0, placements = 1;
    for(int i = 1; i < size; i++)
    {
        if(stalls[i] - stalls[current] >= min_dist)
        {
            placements++;
            current = i;
        }
        if(placements == k) return true;
    }
    return false;
}