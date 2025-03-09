#include <bits/stdc++.h>

using namespace std;

//time: O(n)
//space: O(n)
vector<int> minPartition(int amount)
{
    // code here
    vector<int> coins = {1,2,5,10,20,50,100,200,500,2000};
    vector<int> ans;
    int i = coins.size() - 1;
    while(amount != 0 && i >= 0)
    {
        if(amount >= coins[i])
        {
            amount -= coins[i];
            ans.push_back(coins[i]);
        }
        else i--;
    }
    return ans;
}


int main()
{
}

