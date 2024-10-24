#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge1(vector<vector<int>>& intervals);
vector<vector<int>> merge2(vector<vector<int>>& intervals);

int main()
{
    vector<vector<int>> arr  = {{1,4},{5,6}};
    vector<vector<int>> temp = merge1(arr);
    // vector<vector<int>> temp = merge2(arr);
    for(auto i: temp)
    {
        for(auto j: i)
            cout << j << " ";
        cout << endl;
    }
}

//my approach
//time: O(n) + O(nlogn)
//space: O(n)
vector<vector<int>> merge1(vector<vector<int>>& intervals)
{
    int n = intervals.size(), found = 0, start, end = INT_MIN;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> temp;

    if(n == 1) return intervals;

    for(int i = 0; i < n; i++)
    {
        if(i != n - 1 && intervals[i][1] >= intervals[i + 1][0])
        {
            if(found == 0)
            {
                start = intervals[i][0];
                found = 1;
            }
            int e = max(intervals[i][1], intervals[i + 1][1]);
            end = max(e, end);
        }
        else if (i != n - 1 && intervals[i + 1][0] <= end)
        {
            end = max(intervals[i + 1][1], end);
        }
        else
        {
            if(found == 0)
            {
                start = intervals[i][0];
                end = intervals[i][1];
            }
            found = 0;
            vector<int> t = {start, end};
            temp.push_back(t);
        }
    }
    return temp;
}

//orgasmic
//time: O(nlogn) + O(n)
//space: O(n)
vector<vector<int>> merge2(vector<vector<int>>& intervals)
{
    int n = intervals.size(), found = 0, start, end = INT_MIN;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> temp;

    if(n == 1) return intervals;

    for(int i = 0; i < n; i++)
    {
        if(temp.empty() || intervals[i][0] > temp.back()[1])
            temp.push_back(intervals[i]);
        else
            temp.back()[1] = max(temp.back()[1], intervals[i][1]);
    }
    return temp;
}