#include <bits/stdc++.h>

using namespace std;

int countSubstr(string& s, int k);
int countSubstr1(string& s, int k);
int countSubstr2(string& s, int k);
int countAtMostDistinctChar(string s, int k);

int main()
{
    string s = "aba";
    int ss = countSubstr2(s, 2);
    cout << ss << endl;
}

//brute
//time: O(n^3)
//space: O(n)
int countSubstr(string& s, int k) {
    int count = 0;
    int length = s.length();
    for(int i = 0; i < length; i++)
    {
        for(int j = i; j < length; j++)
        {
            string st = s.substr(i, j - i + 1);
            unordered_set<char> se(st.begin(), st.end());
            if(se.size() == k) count++;
            else if(se.size() > k) break;
        }
    }
    return count;
}

//better
//time: O(n^2)
//space: O(n)
int countSubstr1(string& s, int k) {
    // code here.
    int count, ans = 0;
    int length = s.length();
    for(int i = 0; i < length; i++)
    {
        count = 0;
        unordered_map<char, int> m;
        for(int j = i; j < length; j++)
        {
            if(m[s[j]] == 0) count++;
            m[s[j]]++;
            if(count == k) ans++;
            else if(count > k) break;
        }
    }
    return ans;
}

//k distinct = at most k distinct - at most k-1 distinct
//to find at most k distinct, we will use sliding window and two pointers technique
//time: O(n)
//space: O(n)
int countSubstr2(string& s, int k)
{
    int a = countAtMostDistinctChar(s, k) - countAtMostDistinctChar(s, k - 1);
    return a;
}

int countAtMostDistinctChar(string s, int k)
{
    unordered_map<char, int> m;
    int l = 0, r = -1, count = 0;
    int length = s.length();
    while(r < length)
    {
        if(m.size() <= k)
        {
            count = count + (r - l + 1);
            r++;
            m[s[r]]++;
        }
        else
        {
            m[s[l]]--;
            if(m[s[l]] == 0) m.erase(s[l]);
            l++;
        }
    }
    return count;   
}