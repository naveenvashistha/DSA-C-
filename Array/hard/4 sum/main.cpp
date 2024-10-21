#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum1(vector<int>& nums, int target);
vector<vector<int>> fourSum2(vector<int>& nums, int target);
vector<vector<int>> fourSum3(vector<int>& nums, int target);

int main()
{
    vector<int> v = {2,2,0,1,2,1};
    vector<vector<int>> temp = fourSum1(v, 0);
    for(auto i: temp)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

//brute force
//time: O(N^4 * log(no. of unique triplets)), where N = size of the array.
//space: O(N)
vector<vector<int>> fourSum1(vector<int>& nums, int target)
{
    int n = nums.size();
    set<vector<int>> s;
    for(int l = 0; l < n; l++)
    {
        for(int i = l + 1; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                for(int k = j + 1; k < n; k++)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == target)
                    {
                        vector<int> t = {nums[i], nums[j], nums[k], nums[l]};
                        sort(t.begin(), t.end());
                        s.insert(t);
                    }
                }
            }
        }
    }
    vector<vector<int>> temp(s.begin(), s.end());
    return temp;
}

//better approach
//time: O(N^3 * log(no. of unique triplets))
//space: O(no. of the unique triplets) + O(N (for hashset))
vector<vector<int>> threeSum1(vector<int>& nums, int target)
{
    int n = nums.size();
    set<vector<int>> s;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            set<int> hashset;
            for(int k = j + 1; k < n; k++)
            {
                int fourth = target - (nums[i] + nums[j] + nums[k]);
                if(hashset.find(fourth) != hashset.end())
                {
                    vector<int> t = {nums[i], nums[j], nums[k], fourth};
                    sort(t.begin(), t.end());
                    s.insert(t);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> temp(s.begin(), s.end());
    return temp;
}

//orgasmic
//time: O(N^3) + O(nlogn)
//space: O(1)
vector<vector<int>> threeSum1(vector<int>& nums, int target)
{
    int n = nums.size();
    int j,k;
    long long sum;
    vector<vector<int>> temp;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++)
    {
        if(i != 0 && nums[i] == nums[i - 1]) continue;
        for(int l = i + 1; l < n; l++)
        {
            if(l != i + 1 && nums[l] == nums[l - 1]) continue;
            j = l + 1;
            k = n - 1;
            while(j < k)
            {
                sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if(sum > target)
                    k--;
                else if(sum < target)
                    j++;
                else
                {
                    temp.push_back({nums[i], nums[j], nums[k], nums[l]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                }
                
            }
        }
    }
    return temp;
}