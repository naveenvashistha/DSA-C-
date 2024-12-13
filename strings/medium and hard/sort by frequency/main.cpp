#include <bits/stdc++.h>

using namespace std;
static bool cmp(pair<char, int>& a, pair<char, int>& b);
string frequencySort(string s);

int main()
{
    string s = "tree";
    string ss = frequencySort(s);
    cout << ss << endl;
}

static bool cmp(pair<char, int>& a, pair<char, int>& b)
{
    return a.second > b.second;
}

//better
//time: O(nlogn)
//space: O(n)
string frequencySort(string s) {
    unordered_map<char, int> m;
    for(auto i: s)
        m[i]++;
    vector<pair<char, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    string ans = "";
    for(auto i: v)
    {
        for(int j = 0; j < i.second; j++)
            ans += i.first;
    }
    return ans;
}