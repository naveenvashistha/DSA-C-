#include <iostream>
using namespace std;

void alphaRamp(int n);

int main()
{
    int n;
    cin >> n;
    alphaRamp(n);    
}

void alphaRamp(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++)6
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << (char)(i + 65) << " ";
        }
        cout << endl;
    }
}
