#include <bits/stdc++.h>

using namespace std;

void permutation1(vector<int>& num);
void permutation2(vector<int>& num);

int main()
{
    vector<int> num = {7,1,5,3,6,4};
    // permutation1(num);
    permutation2(num);
    for(auto i: num)
    {
        cout << i << " ";
    } 
    cout << endl;
}

//brute force appraoch: find all the permutation
//search the given permutation and the next one in line is your answer

/************************************************************************/

//find the first dip (or largest prefix)
//then find the number that is only larger than the dip (till dip) and swap them
//sort the array after dip in ascending order 
//time: O(3n)
//space: O(1)
//orgasmic solution
void permutation1(vector<int>& num)
{
    int dip = -1;
    int n = num.size();
    for(int i = n - 2; i >= 0; i--)
    {
        if(num[i] < num[i + 1])
        {
            dip = i;
            break;  
        } 
    }
    if(dip == -1)
    {
        reverse(num.begin(), num.end());
        return;
    }
    for(int i = n - 1; i > dip; i--)
    {
        if(num[dip] < num[i])
        {
            swap(num[dip], num[i]);
            break;
        }
    }
    sort(num.begin() + dip + 1, num.end());
}

//using stl
//time: O(n)
//space: O(1)
void permutation2(vector<int>& num)
{
    next_permutation(num.begin(), num.end());
}