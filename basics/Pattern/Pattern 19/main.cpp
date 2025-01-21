#include <iostream>
using namespace std;

void symmetry(int n);

int main()
{
    int n;
    cin >> n;
    symmetry(n);    
}

void symmetry(int n) {
    // Write your code here.
    int start, end;
    for (int i = 0; i < 2 * n; i++)
    {
        if (i == 0 || i == 2 * n - 1) start = 0, end = 0;
        else if (i < n) start = n - i - 1, end = 2 * i + start + 1;
        else if (i > n) start = i - n, end = 2 * n - start - 1;
        for (int j = 0; j < 2 * n; j++)
        {
            if (j > start && j < end)
            {
                cout << "  ";
            } else {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

