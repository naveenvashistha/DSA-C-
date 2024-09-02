#include <bits/stdc++.h>
using namespace std;

int good_array(int l, int r);

int main()
{
    int n, l, r;
    cin >> n;
    while (n > 0)
    {
        cin >> l >> r;
        cout << good_array(l, r) << endl;
        n--;
    }
}

int good_array(int l, int r)
{
    int i = 0;
    while (l <= r)
    {
        i++;
        l = l + i;
    }
    return i;
}
