#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(n)
//space: O(1)
int countSub(vector<int>& nums, int k){
    int l = 0, r = 0;
    int cnt = 0, count = 0;
    while(r < nums.size()){
        if(nums[r] % 2 != 0) cnt++;
        while(cnt > k){
            if(nums[l] % 2 != 0) cnt--;
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}
int numberOfSubarrays(vector<int>& nums, int k) {
    int g1 = countSub(nums, k);
    int g2 = countSub(nums, k - 1);
    return g1 - g2;
}


int main()
{
}

