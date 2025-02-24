#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(n)
//space: O(1)
int maxScore(vector<int>& cardPoints, int k) {
    int l = 0, r = 0;
    int tot_sum = 0;
    int ans = INT_MIN;
    int window_sum = 0;
    for(int i: cardPoints){
        tot_sum += i;
    }
    while(r < cardPoints.size()){
        if(r - l != cardPoints.size() - k){
            window_sum += cardPoints[r];
            r++;
        }
        else{
            ans = max(tot_sum - window_sum, ans);
            window_sum -= cardPoints[l];
            window_sum += cardPoints[r];
            l++;
            r++;
        }
    }
    return max(tot_sum - window_sum, ans);
}

int main()
{
}

