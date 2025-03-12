#include <bits/stdc++.h>

using namespace std;

//my solution
//time: O(n)
//space: O(1)
int jump(vector<int>& nums) {
    if(nums.size() == 1) return 0;
    int f_ind = 0;
    int jump = 0;
    int furthest_index = nums[0];
    int furthest =  nums[0];
    int i = 1;
    while(i < nums.size())
    {
        if(furthest >= nums.size() - 1) return jump + 1;
        while(i <= furthest_index && i < nums.size())
        {
            if(furthest < i + nums[i])
            {
                furthest = i + nums[i];
                f_ind = i;
            }
            i++;
        }
        i = f_ind + 1;
        furthest_index = furthest;
        jump++;
    }
    return jump;
}


//orgasmic
//time: O(n)
//space: O(1)
int jump(vector<int>& nums) {
    int jumps = 0;
    int l = 0, r = 0;
    while(r < nums.size() - 1)
    {
        int furthest = 0;
        for(int i = l; i <= r; i++)
        {
            furthest = max(furthest, nums[i] + i);
        }
        l = r + 1;
        r = furthest;
        jumps++;
    }
    return jumps;
}

int main()
{
}

