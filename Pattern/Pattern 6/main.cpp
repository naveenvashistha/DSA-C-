#include <iostream>
using namespace std;
void nNumberTriangle(int n);

int main()
{
    int n;
    cin >> n;
    nNumberTriangle(n);
    return 0;
}

void nNumberTriangle(int n) {
    // Write your code here.
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}