#include <bits/stdc++.h>

using namespace std;

int mindays(vector<int>& flowers, int m, int k);
int calculateNoOfBouquets(vector<int>& flowers, int m, int k, int size, int days);

int main()
{
    vector<int> piles = {25, 12, 8, 14, 19};
    int n = mindays(piles, 2, 3);
    cout << n << endl;
}


int calculateNoOfBouquets(vector<int>& flowers, int m, int k, int size, int days)
{
    int bloomedAdjacentFlower = 0;
    int boquets = 0;
    for(int i = 0; i < size; i++)
    {
        if(days >= flowers[i])
        {
            bloomedAdjacentFlower++;
        }
        else
        {
            boquets += bloomedAdjacentFlower / k;
            bloomedAdjacentFlower = 0; 
        }
    }
    boquets += bloomedAdjacentFlower / k;
    return boquets;
}

//orgasmic
//time: O(nlog(maxx))
//space: O(1)
int mindays(vector<int>& flowers, int m, int k)
{
    int n = flowers.size(), min_days = INT_MAX;
    int maxx = INT_MIN;
    int minn = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        maxx = max(maxx, flowers[i]);
        minn = max(minn, flowers[i]);
    }
    int low = minn, mid, high = maxx;
    while(low <= high)
    {
        mid = (low + high) / 2;
        int bouquets = calculateNoOfBouquets(flowers, m, k, n, mid);
        if(bouquets >= m)
        {
            min_days = min(min_days, mid);
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return min_days == INT_MAX ? -1 : min_days;
}

