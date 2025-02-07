//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

//brute
//time: O(n * k)
//space: O(1)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    int i = 0;
    while(k <= nums.size())
    {
        int maxx = INT_MIN;
        for(int m = i; m < k; m++)
        {
            maxx = max(maxx, nums[m]);
        }
        ans.push_back(maxx);
        i++;
        k++;
    }
    return ans;
}

//orgasmic
//time: O(n)
//space: O(k)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> d;
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++)
    {
        if(!d.empty() && i >= k)
        {
            ans.push_back(nums[d.front()]);
            if(d.front() == i - k)
                d.pop_front();
        }
        while(!d.empty() && nums[d.back()] <= nums[i])
            d.pop_back();
        d.push_back(i);
    }
    ans.push_back(nums[d.front()]);
    return ans;
}


int main()
{
    vector<int> heights = {1,3,-1, 2,3,4};
	vector<int> ans = maxSlidingWindow(heights, 3);
    for(auto i: ans)
        cout << i << " ";
    cout << endl;
}
