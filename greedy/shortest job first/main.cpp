#include <bits/stdc++.h>

using namespace std;

//time: O(nlogn)
//space: O(1)
long long solve(vector<int>& bt) {
    // code here
    sort(bt.begin(), bt.end());
    long long waiting_time = 0;
    long long sum = 0;
    for(int i = 1; i < bt.size(); i++)
    {
        waiting_time += bt[i - 1];
        sum += waiting_time;
    }
    return sum / bt.size();
}


int main()
{
}

