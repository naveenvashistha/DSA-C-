#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(n)
//space: O(n)
int characterReplacement(string s, int k) {
    unordered_map<char, int> mp;
    int mmf = INT_MIN;
    int len = 0;
    int start = 0;
    for(int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
        mmf = max(mmf, mp[s[i]]);
        while(i - start + 1 - mmf > k)
        {
            mp[s[start]]--;
            start++;
            mmf = INT_MIN;
            for(auto p: mp){
                if(mmf < p.second) mmf = p.second;
            }
        }
        len = max(len, i - start + 1);
    }
    return len;
}

//orgasmic
//time: O(n)
//space: O(n)
int characterReplacement(string s, int k) {
    unordered_map<char, int> mp;
    int mmf = INT_MIN;
    int len = 0;
    int start = 0;
    for(int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
        mmf = max(mmf, mp[s[i]]);
        if(i - start + 1 - mmf > k)
        {
            mp[s[start]]--;
            start++;
        }
        len = max(len, i - start + 1);
    }
    return len;
}