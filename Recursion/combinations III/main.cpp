#include <bits/stdc++.h>

using namespace std;

vector<string> letterCombinations(string digits);
void findCombinations(vector<string> &ans, vector<string> &letters, string digits, int ind, string &s);

int main()
{
    vector<string> out = letterCombinations("1");
    for(auto i: out)
    {
        cout << i << endl;
    }
}

void findCombinations(vector<string> &ans, vector<string> &letters, string digits, int ind, string &s)
{
    if(ind == digits.size())
    {
        ans.push_back(s);
        return;
    }
    string str = letters[digits[ind] - '2'];
    for(int i = 0; i < str.length(); i++)
    {
        s.push_back(str[i]);
        findCombinations(ans, letters, digits, ind + 1, s);
        s.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.length() == 0) return ans;
    vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string s = "";
    findCombinations(ans, letters, digits, 0, s);
    return ans;
}