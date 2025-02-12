#include <bits/stdc++.h>

using namespace std;

//my solution
//time: O(n)
//space: O(no of zeroes) (can also use loop instead of queue but that would make TC O(2n))
int longestOnes(vector<int>& nums, int k) {
    queue<int> indx;
    int temp = k;
    int start = 0;
    int len = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0)
        {
            if(k == 0) start = i + 1;
            else if(temp != 0){
                temp--;
                indx.push(i);
            }
            else if(temp == 0){
                start = indx.front() + 1;
                indx.pop();
                indx.push(i);
            }
        }
        len = max(len, i - start + 1);
    }
    return len;
}

int main()
{
}

