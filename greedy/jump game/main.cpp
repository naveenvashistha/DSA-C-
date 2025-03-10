#include <bits/stdc++.h>

using namespace std;

//time: O(n)
//space: O(1)
bool canJump(vector<int>& nums) {
    int furthest = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        furthest = max(furthest, i + nums[i]);
        if(furthest == nums.size() - 1) return true;
        if(furthest == i) return false;
    }
    return true;
}

int main()
{
}

