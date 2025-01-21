#include <iostream>
using namespace std;

void getNumberPattern1(int n);
void getNumberPattern2(int n);

int main()
{
    int n;
    cin >> n;
    getNumberPattern1(n);
    cout << endl;
    getNumberPattern2(n);    
}

void getNumberPattern1(int n) {
    // Write your code here.
    for (int i = 0; i < 2*n - 1; i++)
    {
        for (int j = 0; j < 2*n - 1; j++)
        {
            if (i <= n - 1 && j <= n - 1)
            {
                if (i <= j)cout << n - i;
                else cout << n - j;
            }
            else if (i > n - 1 && j <= n - 1)
            {
                if (2*n - 2 - i <= j)cout << n - (2*n - 2 - i);
                else cout << n - j; 
            }
            else if (i <= n - 1 && j > n - 1)
            {
                if (i <= 2*n - 2 - j) cout << n - i;
                else cout << n - (2*n - 2 - j);
            }
            else
            {
                if (2*n - 2 - i <= 2*n - 2 - j)cout << n - (2*n - 2 - i);
                else cout << n - (2*n - 2 - j);
            }
        }
        cout << endl;
    }
}

void getNumberPattern2(int n)
{
    int top, left, right, bottom;
    for (int i = 0; i < 2*n - 1; i++)
    {
        for (int j = 0; j < 2*n - 1; j++)
        {
            top = i;
            left = j;
            right = 2*n - 2 - j;
            bottom = 2*n - 2 - i;
            cout << n - min(min(top, bottom), min(left, right));
        }
        cout << endl;
    }

}