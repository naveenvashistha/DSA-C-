#include <bits/stdc++.h>

using namespace std;

int longestSuccessiveElements1(vector<int>&a);
int longestSuccessiveElements2(vector<int>&a);

int main()
{
    vector<int> num = {15, 6, 2, 1, 16, 4, 2, 29, 9, 12, 8, 5, 14, 21, 8, 12, 17, 16, 6, 26, 3 };
    int n = longestSuccessiveElements1(num);
    // int n = longestSuccessiveElements2(num);
    cout << n << endl;
}

//brute force would be to check for each element x if x + 1, x+2, etc exist in the array and then returning the max_ones in the end.

//my approach and also better approach
//time: O(nlogn)
//space: (O(1)
int longestSuccessiveElements1(vector<int>& num) {
    // Write your code here.
    int max_ones = 1, ones = 1;
    int n = num.size();
    if(n == 0) return 0;
    sort(num.begin(), num.end());
    for(int i = 0; i < n - 1; i++)
    {
        if(num[i] == num[i + 1])
            continue;
        else if(abs(num[i] - num[i + 1]) == 1)
        {
            ones++;
        }
        else
        {
            max_ones = max(max_ones, ones);
            ones = 1;
        }
    }
    return max(ones, max_ones);
}

//orgasmic solution
//If a number, num, is a starting number, ideally, num-1 should not exist. So, for every element, x, in the set, we will check if x-1 exists inside the set
//If x-1 exists: This means x cannot be a starting number and we will move on to the next element in the set.
//If x-1 does not exist: This means x is a starting number of a sequence. So, for number, x, we will start finding the consecutive elements.
//Though we are using nested loops, the set will be traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).
//time: O(n) + O(2n)
//space: O(n)
int longestSuccessiveElements2(vector<int>& num) {
    unordered_set<int> s(num.begin(), num.end());
    int n = s.size(), j;
    int ones = 1, max_ones = 1;
    for(auto i: s)
    {
        if(s.find(i - 1) == s.end())
        {
            j = 1;
            while(s.find(i + j) != s.end())
            {
                ones += 1;
                j++;
            }
            max_ones = max(max_ones, ones);
            ones = 1;
            j = 1;
        }
    }
    return max_ones;
}