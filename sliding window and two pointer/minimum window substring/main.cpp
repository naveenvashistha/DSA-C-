#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(n)
//space: O(n)
string minWindow(string s, string t) {
    int l = 0, r = 0;
    int min_len = INT_MAX;
    int min_start = 0;
    int cnt = 0;
    unordered_map<char, int> mp;
    for(char c : t) mp[c]++;
    while(r < s.length()){
        if(mp.find(s[r]) != mp.end() && mp[s[r]] > 0) cnt++;
        mp[s[r]]--;
        while(cnt == t.length()){
            if(min_len > r - l + 1){
                min_len = r - l + 1;
                min_start = l;
            }
            mp[s[l]]++;
            if(mp[s[l]] > 0) cnt--;
            l++;
        }
        r++;
    }
    if(min_len == INT_MAX) return "";
    return s.substr(min_start, min_len);
}


int main()
{
}

