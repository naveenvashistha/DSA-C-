#include <iostream>
#include <vector>
using namespace std;

vector<int> passedBy(int a, int &b);

int main()
{
    int a, b;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    vector<int> vec = passedBy(a, b);
    cout << vec.at(0) << " " << vec.at(1) << endl;
    return 0;
}

//time - O(1)
//space - O(1)
vector<int> passedBy(int a, int &b)
{
    return {a + 1, b + 2};
}