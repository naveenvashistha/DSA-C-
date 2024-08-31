#include <iostream>
using namespace std;
void nStarTriangle2(int n);
void nStarTriangle1(int n);

int main()
{
    int n;
    cin >> n;
    nStarTriangle1(n);
    nStarTriangle2(n);
    return 0;
}

void nStarTriangle1(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + i; j++)
        {
            if (j < n - i - 1)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}

void nStarTriangle2(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1 - i; j++)
        {
            if (j < i)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}