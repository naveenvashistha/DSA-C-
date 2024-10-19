#include <bits/stdc++.h>

using namespace std;

int subarraySum1(vector<int>& nums, int k);
int subarraySum2(vector<int>& nums, int k);

int main()
{
    vector<int> num = {1,2,3,4};
    // int n = subarraySum1(num, 3);
    int n = subarraySum2(num, 3);
    cout << n << endl;
}

//better approach and my approach too
//time: O(n^2)
//space: O(1)
int subarraySum1(vector<int>& nums, int k)
{
    int size = nums.size(), sum, count = 0;
    for(int i = 0; i < size; i++)
    {
        sum = 0;
        for(int j = i; j < size; j++)
        {
            sum += nums[j];
            if(sum == k)
                count++;
        }
    }
    return count;
}

//orgasmic soln
//counting how many times sum - k comes
//time: O(n)
//space: O(n)
int subarraySum2(vector<int>& nums, int k)
{
    int size = nums.size(), sum = 0, count = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for(int i = 0; i < size; i++)
    {
        sum += nums[i];
        count += m[sum - k];
        m[sum] += 1;
    }
    return count;
}