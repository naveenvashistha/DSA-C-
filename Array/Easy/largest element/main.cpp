#include <bits/stdc++.h>

using namespace std;

void largestElement(vector<double> &arr, int size);

int main()
{
    int size, n;
    vector<double> num;
    cout << "size: ";
    do
    {
        cin >> size;
    } while (size <= 0);
    while(size--)
    {
        cin >> n;
        num.push_back(n);
    }
    largestElement(num, num.size());
}

//time: O(n)
//space: O(1)
void largestElement(vector<double> &arr, int size)
{
    int m = arr[0];
    for(int i = 1; i < size; i++)
    {
        if (m < arr[i])
            m = arr[i];
    }
    cout << "largest element is: " << m;
    return;
}