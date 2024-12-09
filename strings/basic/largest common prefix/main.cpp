#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs);


int main()
{
    vector<string> s = {"fl", "flower", "floi"};
    string ss = longestCommonPrefix(s);
    cout << ss << endl;
}

//orgasmic
//time: O(n^2)
//space: O(1)
string longestCommonPrefix(vector<string>& strs) {
    int length = strs.size();
    int i = 0;
    string ans = "";
    while(true)
    {
        if(strs[0].length() == 0 || strs[0][i] == '\0') return ans;
        char ch = strs[0][i];
        for(int j = 0; j < length; j++)
        {
            if(strs[j].length() == 0 || strs[j][i] == '\0' || ch != strs[j][i])
                return ans;
        }
        ans += ch;
        i++;
    }
    return ans;
}