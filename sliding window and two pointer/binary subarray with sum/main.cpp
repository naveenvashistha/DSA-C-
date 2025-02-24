#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(n)
//space: O(1)
int countSub(vector<int>& nums, int goal){
    if(goal < 0) return 0;
    int l = 0;
    int r = 0;
    int g = 0, cnt = 0;
    while(r < nums.size())
    {
        g = g + nums[r];
        while(g > goal) 
        {
            g = g - nums[l];
            l++;
        }
        cnt += (r - l + 1);
        r++;    
    }
    return cnt;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int g1 = countSub(nums, goal);
    int g2 = countSub(nums, goal - 1);
    return g1 - g2;
}


int main()
{
}

