#include <bits/stdc++.h>

using namespace std;

void genParenthesis(vector<string> &s, string st, int n1, int n2);
vector<string> generateParenthesis(int n);

int main()
{
    vector<string> s = generateParenthesis(3);
    for(auto i: s)
    {
        cout << i << endl;
    }
}

void genParenthesis(vector<string> &s, string st, int n1, int n2)
{
    if(n1 == 0 && n2 == 0)
    {
        s.push_back(st);
        return;
    }
    if(n1 > 0)  genParenthesis(s, st + "(", n1 - 1, n2);
    if(n2 > n1) genParenthesis(s, st + ")", n1, n2 - 1);
}

//orgasmic
//time: O(N*2^N) where N = 2*n
//space: O(N)
vector<string> generateParenthesis(int n) {
    vector<string> s;
    genParenthesis(s, "", n, n);
    return s;
}