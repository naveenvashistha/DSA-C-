#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int start, int end);
void findCombinations(vector<vector<string>> &v, vector<string> &str, string s, int ind);
vector<vector<string>> partition(string s);

int main()
{
    string s = "aabb";
    vector<vector<string>> out = partition(s);
    for(auto i: out)
    {
        for(auto j: i)
            cout << j << " ";
        cout << endl;
    }
}

bool isPalindrome(string s, int start, int end)
{
    while(start <= end)
    {
        if(s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}
void findCombinations(vector<vector<string>> &v, vector<string> &str, string s, int ind)
{
    if(ind == s.size())
    {
        v.push_back(str);
        return;
    }
    for(int i = ind; i < s.size(); i++)
    {
        if(isPalindrome(s, ind, i))
        {
            str.push_back(s.substr(ind, i - ind + 1));
            findCombinations(v, str, s, i + 1);
            str.pop_back();
        }
    }
}

//orgasmic
//time: O((2^n)*k*(n/2))
//space: O(k*x)
vector<vector<string>> partition(string s)
{
    vector<vector<string>> v;
    vector<string> str;
    findCombinations(v, str, s, 0);
    return v;
}