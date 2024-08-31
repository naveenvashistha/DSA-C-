#include <iostream>
using namespace std;

void nBinaryTriangle(int n);

int main()
{
    int n;
    cin >> n;
    nBinaryTriangle(n);    
}

void nBinaryTriangle(int n) {
    // Write your code here.
    int binary;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            binary = 0;
        }
        else
        {
            binary = 1;
        }
        for (int j = 0; j < i; j++)
        {
            cout << binary << " ";
            binary = 1 - binary;
        }
        cout << endl;
    }
}