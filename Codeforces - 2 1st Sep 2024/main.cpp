#include <bits/stdc++.h>
using namespace std;

string beautiful(int first, string second);

int main()
{
    int n, m;
    cin >> n;
    string s;
    while (n > 0)
    {
        cin >> m >> s;
        cout << beautiful(m, s) << endl;
        n--;
    }
}

string beautiful(int m, string s)
{
    double sq = sqrt(m);
    if (m == sq * sq)
    {
        for (int i = 1; i <= sq; i++)
        {
            for (int j = 1; j <= sq; j++)
            {
                if (i == 1 || i == sq || j == 1 || j == sq)
                {
                    if (s[(i - 1) * sq + j - 1] != '1') return "No";
                }
                else
                {
                    if (s[(i - 1) * sq + j - 1] != '0') return "No";
                }
            }
        }
        return "Yes";
    }
    return "No";
}
