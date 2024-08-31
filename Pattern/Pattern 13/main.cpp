#include <iostream>
using namespace std;

void nNumberTriangle(int n);

int main()
{
    int n;
    cin >> n;
    nNumberTriangle(n);    
}

void nNumberTriangle(int n) {
    // Write your code here.
    int pattern = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << pattern << " ";
            pattern += 1; 
        }
        cout << endl;
    }
}