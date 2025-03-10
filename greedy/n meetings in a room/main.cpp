#include <bits/stdc++.h>

using namespace std;

//time: O(nlogn)
//space: O(n)
int maxMeetings(vector<int>& start, vector<int>& end) {
    // Your code here
    int count = 0;
    int next_time = -1;
    vector<pair<int, int>> time;
    for(int i = 0; i < start.size(); i++)
        time.push_back({end[i], start[i]});
    sort(time.begin(), time.end());
    for(int i = 0; i < time.size(); i++)
    {
        if(time[i].second > next_time)
        {
            next_time = time[i].first;
            count++;   
        }
    }
    return count;
}

int main()
{
}

