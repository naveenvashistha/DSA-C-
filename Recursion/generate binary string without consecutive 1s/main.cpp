#include <bits/stdc++.h>

using namespace std;

vector<string> generateString(int N);
void arrayBinaryString(vector<string> &s, int N, string st);

int main()
{
    vector<string> s = generateString(3);
    for(auto i: s)
    {
        cout << i << endl;
    }
}

void arrayBinaryString(vector<string> &s, int N, string st)
{
    if(N == 0)
    {
        s.push_back(st);
        return;
    }
    if(st.length() == 0 || st[st.length() - 1] == '0')
    {
        arrayBinaryString(s, N - 1, st + "0");
        arrayBinaryString(s, N - 1, st + "1");
    }
    else
    {
        arrayBinaryString(s, N - 1, st + "0");
    }
}

//orgasmic
//time: O(N*2^N)
//space: O(N)
vector<string> generateString(int N) {
    // Write your code here.
    vector<string> s;
    arrayBinaryString(s, N, "");
    return s;
}