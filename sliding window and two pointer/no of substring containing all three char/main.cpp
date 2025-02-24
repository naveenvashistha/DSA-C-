#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(n)
//space: O(1)
int numberOfSubstrings(string s) {
    int l = 0, r = 0;
    int cnt = 0;
    unordered_map<char, int> mp;
    while(r < s.length())
    {
        mp[s[r]]++;
        while(mp.size() == 3){
            cnt += (s.length() - r);
            mp[s[l]]--;
            if(mp[s[l]] == 0) mp.erase(s[l]);
            l++;
        }
        r++;
    }
    return cnt;
}

int main()
{
}

