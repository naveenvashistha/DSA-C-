#include <iostream>
using namespace std;


string compareNM(int n, int m);

int main()
{
    int n, m;
    cout << "N: ";
    cin >> n;
    cout << "M: ";
    cin >>  m;
    cout << compareNM(n, m) << endl;
    return 0;
}

string compareNM(int n, int m){
        // code here
        if (n > m)
        {
            return "greater";
        }
        else if (n < m)
        {
            return "lesser";
        }
        else
        {
            return "equal";
        }
    }