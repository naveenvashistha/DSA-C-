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