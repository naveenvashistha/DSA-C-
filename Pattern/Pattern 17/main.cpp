#include <iostream>
using namespace std;

void alphaHill(int n);

int main()
{
    int n;
    cin >> n;
    alphaHill(n);    
}

void alphaHill(int n) {
    // Write your code here.
    char ch;
    for (int i = 0; i < n; i++)
    {
        ch = 'A' - 1;
        for (int j = 0; j < n + i; j++)
        {
            if (j < n - 1 - i)
            {
                cout << "  ";
            } 
            else if (j < n)
            {
                cout  << ++ch << " ";
            }
            else
            {
                cout << --ch << " ";
            }
        }
        cout << endl;
    }
}