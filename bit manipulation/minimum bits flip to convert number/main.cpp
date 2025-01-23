#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums);

int main()
{
    vector<int> nums = {1,2,3,3,2};
    cout << singleNumber(nums) << endl;
}

//orgasmic
//time: O(n)
//space: O(1)
int singleNumber(vector<int>& nums) {
    int count = 0;
    for(auto i: nums)
    {
        count = count ^ i;
    }
    return count;
}