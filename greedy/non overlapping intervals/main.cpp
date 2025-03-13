#include <bits/stdc++.h>

using namespace std;

//time: O(nlogn)
//space: O(1)
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int i = 0, j = 1;
    int ans = 0;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    while(j < n)
    {
        if(intervals[i][1] <= intervals[j][0])
        {
            i = j;
            j++;
        }
        else
        {
            if(intervals[i][1] < intervals[j][1]){
                j++;
                ans++;
            }
            else{
                i = j;
                j++;
                ans++;
            }
        }
    }
    return ans;
}


//same as n meetings in a room
//time: O(nlogn)
//space: O(1)
bool static comp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), comp);
    int next = INT_MIN, count = 0;
    for(int i = 0; i < intervals.size(); i++)
    {
        if(intervals[i][0] >= next)
        {
            next = intervals[i][1];
            count++;
        }
    }
    return intervals.size() - count;
}


int main()
{
}

