#include <bits/stdc++.h>
using namespace std;

int dataTypeSize(string str);
string checksum(int first, int second);

int main()
{
    int n,  first, second;
    cin >> n;
    while (n > 0)
    {
        cin >> first >> second;
        cout << checksum(first, second) << endl;
        n--;
    }
}

string checksum(int first, int second)
{
    if (first > 1)
    {
        if (first  % 2 == 0) return "Yes";
    }
    else if (first  == 0)
    {
        if (second % 2 == 0) return "Yes";
    }
    return "No";
}
