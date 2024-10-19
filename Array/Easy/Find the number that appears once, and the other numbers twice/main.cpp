#include <bits/stdc++.h>

using namespace std;

int singleNumber1(vector<int>& nums);
int singleNumber2(vector<int>& nums);
int singleNumber3(vector<int>& nums);

int main()
{
    vector<int> nums {4,1,2,2,1};
    // int n = singleNumber1(nums);
    // int n = singleNumber2(nums);
    int n = singleNumber3(nums);
    cout << n << endl; 
}

//my approach
//time: O(n) for best and average but O(n^2) for worst
//space: O(n)
int singleNumber1(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int sum1 = 0, sum2 = 0;
    for(auto i: s)
    {
        sum1 += i * 2;
    }
    for(int i = 0; i < nums.size(); i++)
    {
        sum2 += nums[i];
    }
    return sum1 - sum2;
}

//better approach
//time: O(n) for best and average but O(n^2) for worst
//space: O(n)
int singleNumber2(vector<int>& nums) {
    unordered_map<int, int> s;
    for(int i = 0; i < nums.size(); i++)
    {
        s[nums[i]]++;
    }
    for(auto i: s)
    {
        if (i.second == 1)
            return i.first;
    }
    return -1;
}

//optimal approach
//time: O(n)
//space: O(1)
int singleNumber3(vector<int>& nums) {
    int xor1 = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        xor1 ^= nums[i];
    }
    return xor1;
}