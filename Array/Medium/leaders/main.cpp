#include <bits/stdc++.h>

using namespace std;

vector<int> superiorElements1(vector<int>&a);
vector<int> superiorElements2(vector<int>&a); 

int main()
{
    vector<int> num = {4,3,2,6,5,1,2};
    // vector<int> a = superiorElements1(num);
    vector<int> a = superiorElements2(num);
    for(auto i: a)
    {
        cout << i << " ";
    } 
    cout << endl;
}

//brute force and handles duplicates
//can also use set and then convert it to vector at end (will also handle duplicate)
//time: O(n^2)
//space: O(n)
vector<int> superiorElements1(vector<int>&a) {
    int n = a.size();
    vector<int> num;
    for(int i = 0; i < n - 1; i++)
    {
        bool found = false;
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] < a[j])
            {
                found = true;
                break;
            }
        }
        if(found == false && (num.empty() || a[i] != num.back()))
            num.push_back(a[i]);
    }
    if(num.empty() || a[n - 1] != num.back())
        num.push_back(a[n - 1]);
    return num;
}

//orgasmic approach and handles duplicates
//time: O(n)
//space: O(n)
vector<int> superiorElements2(vector<int>&a)
{
    int n = a.size();
    int max = a[n - 1];
    vector<int> num;
    for(int i = n - 2; i >= 0; i--)
    {
        if(a[i] > max)
        {
            max = a[i];
            num.push_back(a[i]);
        }
    }
    num.push_back(a[n - 1]);
    return num;
}

