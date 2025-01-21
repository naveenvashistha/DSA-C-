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
        for (char j = 'A'; j < 'A' + (n - i); j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}