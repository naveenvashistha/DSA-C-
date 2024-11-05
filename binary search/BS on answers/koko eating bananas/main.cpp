#include <bits/stdc++.h>

using namespace std;

int minbananas1(vector<int>& piles, int h);
int minbananas2(vector<int>& piles, int h);
int calculateTime(vector<int>& piles, int i);

int main()
{
    vector<int> piles = {25, 12, 8, 14, 19};
    int n = minbananas1(piles, 5);
    cout << n << endl;
}

//brute force
//time: O(n) + O(n*maxx)
//space: O(1)
int minbananas1(vector<int>& piles, int h)
{
    int n = piles.size(), min_k = INT_MAX;
    int maxx = piles[0];
    for(int i = 0; i < n; i++)
    {
        maxx = max(maxx, piles[i]);
    }
    for(int i = 1; i <= maxx; i++)
    {
        int k = calculateTime(piles, i);
        if(k <= h)
        {
            min_k = min(min_k, k);
        }
    }
    return min_k;
}

int calculateTime(vector<int>& piles, int i)
{
    int hour = 0;
    for(int i = 0; i < piles.size(); i++)
    {
        if(piles[i] % i == 0)
            hour += piles[i] / i;
        else
            hour += piles[i] / i + 1;  
    }
    return hour;
}

//orgasmic
//time: O(nlog(maxx))
//space: O(1)
int minbananas2(vector<int>& piles, int h)
{
    int n = piles.size(), min_k = INT_MAX;
    int maxx = piles[0];
    for(int i = 0; i < n; i++)
    {
        maxx = max(maxx, piles[i]);
    }
    int low = 1, mid, high = maxx;
    while(low <= high)
    {
        mid = (low + high) / 2;
        int t = calculateTime(piles, mid);
        if(t <= h)
        {
            min_k = min(min_k, mid);
        }
        else high = mid - 1;
    }
    return min_k;
}

