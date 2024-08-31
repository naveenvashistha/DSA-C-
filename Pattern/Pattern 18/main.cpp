#include <iostream>
using namespace std;

void alphaTriangle(int n);

int main()
{
    int n;
    cin >> n;
    alphaTriangle(n);    
}

void alphaTriangle(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > n - i - 1; j--)
        {
            cout << (char)(j - 1 + 'A') << " "; 
        }
        cout << endl;
    }
}