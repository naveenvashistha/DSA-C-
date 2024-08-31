#include <iostream>
using namespace std;

void numberCrown(int n);

int main()
{
    int n;
    cin >> n;
    numberCrown(n);    
}

void numberCrown(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if(j > i && j < 2 * n - i - 1)
            {
                cout << "  ";
            }
            else if (j <= i)
            {
                cout << j + 1 << " ";
            }
            else if (j >= 2*n - 1 - i)
            {
                cout << 2 * n - j << " ";
            }
        }
        cout << endl;
    }
}