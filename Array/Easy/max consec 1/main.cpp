#include <bits/stdc++.h>

using namespace std;

int maxConsec(vector<int> num);

int main()
{
    vector<int> num {1,1,1,1,1,0,0,1,1,1,1,1,1,0,1,1,1,1,0,1,0};
    int n = maxConsec(num);
    cout << n << endl;
}

//time: O(n)
//space: O(1)
int maxConsec(vector<int> num)
{
    int max = 0, temp = 0;
    for(int i = 0; i < num.size(); i++)
    {
        if(num[i] == 1)
            temp++;
        else
        {
            if(max < temp)
                max = temp;
            temp = 0;
        }
    }
    return max;
}