#include <bits/stdc++.h>

using namespace std;

//time: O(n)
//space: O(1)
bool lemonadeChange(vector<int>& bills) {
    unordered_map<int, int> currency;
    for(int i: bills)
    {
        if(i == 10)
        {
            if(currency[5] == 0) return false;
            currency[5]--;
        }
        else if(i == 20)
        {
            if(currency[10] == 0)
            {
                if(currency[5] < 3) return false;
                currency[5] -= 3;
            }
            else
            {
                if(currency[5] == 0) return false;
                currency[5]--;
                currency[10]--;
            }
        }
        currency[i]++;
    }
    return true;
}


int main()
{
}

