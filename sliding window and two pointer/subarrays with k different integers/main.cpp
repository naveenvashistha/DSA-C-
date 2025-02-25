#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(n)
//space: O(n)
int countSub(vector<int>& nums, int k) {
    int l = 0, r = 0;
    int cnt = 0;
    unordered_map<int, int> mp;
    while(r < nums.size()){
        mp[nums[r]]++;
        while(mp.size() > k){
            mp[nums[l]]--;
            if(mp[nums[l]] == 0) mp.erase(nums[l]);
            l++;
        }
        cnt += (r - l + 1);
        r++;
    }
    return cnt;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    int g1 = countSub(nums, k);
    int g2 = countSub(nums, k - 1);
    return g1 - g2;
}


int main()
{
}

