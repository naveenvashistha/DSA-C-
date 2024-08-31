#include <iostream>
using namespace std;

void nStarTriangle1(int n);
void nStarTriangle2(int n);

int main()
{
    int n;
    cin >> n;
    nStarTriangle1(n);  
    nStarTriangle2(n);    
}

void nStarTriangle1(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for(int j = n - 1; j > i; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void nStarTriangle2(int n)
{
    int stars;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        stars = i;
        if (i > n)
        {
            stars = 2 * n - i;
        }
        for (int j = 0; j < stars; j++)
        {
            cout << "*";
        } 
        cout << endl;
    }
}