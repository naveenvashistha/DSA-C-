#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(n)
//space: O(n)
int kDistinctChars(int k, string &str)
{
    // Write your code here
    int l = 0, r = 0;
    unordered_map<char, int> mp;
    int len = 0;
    while(r < str.length())
    {
        mp[str[r]]++;
        while(mp.size() > k)
        {
            mp[str[l]]--;
            if(mp[str[l]] == 0) mp.erase(str[l]);
            l++;
        }
        len = max(len, r - l + 1);
        r++;
    }
    return len;
}


int main()
{
}

