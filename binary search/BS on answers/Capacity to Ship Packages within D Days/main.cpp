#include <bits/stdc++.h>

using namespace std;

int ship1(vector<int>& weights, int days);
int ship2(vector<int>& weights, int days);
bool calculateDays(vector<int>& weights, int capacity, int size, int daysthreshold);

int main()
{
    vector<int> piles = {25, 12, 8, 14, 19};
    int n = ship1(piles, 5);
    cout << n << endl;
}

//brute force
//time: O(n) + O(n*(sum - maxx))
//space: O(1)
int ship1(vector<int>& weights, int days)
{
    int n = weights.size();
    long long sum = 0;
    int maxx = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        sum += weights[i];
        maxx = max(maxx, weights[i]);
    }
    if(days == 1) return sum;
    for(int i = maxx; i <= sum; i++)
    {
        bool possible = calculateDays(weights, i, n, days);
        if(possible)
        {
            return i;
        }
    }
    return -1;
}

bool calculateDays(vector<int>& weights, int capacity, int size, int daysThreshold)
{
    long long days = 0, sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += weights[i];
        if(sum > capacity)
        {
            sum = weights[i];
            days++;
        }
    }
    if(sum <= capacity)
        days++;
    return days <= daysThreshold;
}

//orgasmic
//time: O(nlog(sum - maxx))
//space: O(1)
int divisor2(vector<int>& weights, int days)
{
    int n = weights.size(), min_capacity = INT_MAX;
    int maxx = INT_MIN;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += weights[i];
        maxx = max(maxx, weights[i]);
    }
    if(days == 1) return sum;
    int low = maxx, mid, high = sum;
    while(low <= high)
    {
        mid = (low + high) / 2;
        bool t = calculateDays(weights, mid, n, days);
        if(t)
        {
            min_capacity = min(min_capacity, mid);
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return min_capacity;
}

