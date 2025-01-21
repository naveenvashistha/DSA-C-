#include <iostream>
using namespace std;
void nStarTriangle(int n);

int main()
{
    int n;
    cin >> n;
    nStarTriangle(n);
    return 0;
}

void nStarTriangle(int n) {
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