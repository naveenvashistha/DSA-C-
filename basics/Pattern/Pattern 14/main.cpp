#include <iostream>
using namespace std;

void nLetterTriangle(int n);

int main()
{
    int n;
    cin >> n;
    nLetterTriangle(n);    
}

void nLetterTriangle(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << (char)(j + 'A') << " ";
        }
        cout << endl;
    }
}