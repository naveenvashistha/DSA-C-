#include <bits/stdc++.h>

using namespace std;

bool findCombination1(string s, vector<string> wordDict, string str);
bool wordBreak1(string s, vector<string>& wordDict);

int main()
{
    vector<string> word = {"leet", "code"};
    string s = "leetcode";
    cout << wordBreak1(s, word) << endl; 
}

bool findCombination1(unordered_set<string> &ss, string s, int ind, int size)
{
    if(ind == size)
    {
        return true;
    }
    string p = "";
    bool r = false;
    for(int i = ind; i < size; i++)
    {
        p = p + s[i];
        if(ss.find(p) != ss.end())
        {
            r = r || findCombination1(ss, s, i + 1, size);
            if(r == true) return r;
        }
    }
    return r;
}

//using partioning method
//time: O(2^n) 
//space: O(n) recursive space and O(n) storage space
bool wordBreak1(string s, vector<string>& wordDict) {
    unordered_set<string> ss;
    for(auto i: wordDict)
    {
        ss.insert(i);
    }
    bool res = findCombination1(ss, s, 0, s.size());
    return res;
}