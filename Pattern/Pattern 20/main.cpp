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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        for (int j = 0; j < 2*n - 2*i - 2; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout  << "* ";
        }
        cout << endl;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << "* ";
        }
        for (int j = 0; j < 2*i; j++)
        {
            cout << "  ";
        }
        for (int j = i; j < n; j++)
        {
            cout  << "* ";
        }
        cout << endl;
    }
}
