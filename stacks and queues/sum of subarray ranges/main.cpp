
#include <bits/stdc++.h>
using namespace std;

long long maxSub(vector<int>& nums);
long long minSub(vector<int>& nums); 
long long subArrayRanges(vector<int>& nums);

int main()
{
    vector<int> n = {1,2,3,4};
    cout << subArrayRanges(n) << endl;
}

long long minSub(vector<int>& nums)
{
    vector<long long> nse(nums.size(), nums.size());
    vector<long long> pse(nums.size(), -1);
    stack<long long> st;
    stack<long long> stt;

    for(int i = nums.size() - 1; i >= 0; i--)
    {
        while(!st.empty() && nums[st.top()] >= nums[i])
            st.pop();
        if(!st.empty()) nse[i] = st.top();
        st.push(i);
    }

    for(int i = 0; i < nums.size(); i++)
    {
        while(!stt.empty() && nums[stt.top()] > nums[i])
            stt.pop();
        if(!stt.empty()) pse[i] = stt.top();
        stt.push(i);
    }

    long long sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        long long left = i - pse[i];
        long long right = nse[i] - i;
        sum = sum + (left * right * nums[i]);
    }
    return sum;
}

long long maxSub(vector<int>& nums)
{
    vector<long long> nge(nums.size(), nums.size());
    vector<long long> pge(nums.size(), -1);
    stack<long long> st;
    stack<long long> stt;

    for(int i = nums.size() - 1; i >= 0; i--)
    {
        while(!st.empty() && nums[st.top()] <= nums[i])
            st.pop();
        if(!st.empty()) nge[i] = st.top();
        st.push(i);
    }

    for(int i = 0; i < nums.size(); i++)
    {
        while(!stt.empty() && nums[stt.top()] < nums[i])
            stt.pop();
        if(!stt.empty()) pge[i] = stt.top();
        stt.push(i);
    }

    long long sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        long long left = i - pge[i];
        long long right = nge[i] - i;
        sum = sum + (left * right * nums[i]);
    }
    return sum;
}

//orgasmic
//time: O(n)
//space: O(n)
long long subArrayRanges(vector<int>& nums) {
    long long minn = minSub(nums);
    long long maxx = maxSub(nums);
    return maxx - minn;
}