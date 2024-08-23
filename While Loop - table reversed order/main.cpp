#include <iostream>
using namespace std;

int main()
{
    int n, mutliplier = 10;
    do
    {
        cin >> n;
    } while(n < 1 || n > 10000);

    while(mutliplier > 0)
    {
        cout << n * mutliplier << " ";
        mutliplier--;
    }
    
}