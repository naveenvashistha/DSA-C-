//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


//orgasmic
//time: O(n)
//space: O(n)
string removeKdigits(string num, int k) {
    if(k == num.length()) return "0";
    string s = "";
    int i = 0;
    while(i < num.length())
    {
        while(!s.empty() && k != 0 && s.back() > num[i])
        {
            s.pop_back();
            k--;
        }
        s.push_back(num[i]);
        i++;
    }
    while(k != 0)
    {
        s.pop_back();
        k--;
    }
    int j = 0;
    while(s[j] == '0' && j < s.length())
        j++;
    s = s.substr(j, s.length() - j);
    return s.empty() ? "0" : s;
}

int main()
{
	cout << removeKdigits("12345", 3) << endl;
}
