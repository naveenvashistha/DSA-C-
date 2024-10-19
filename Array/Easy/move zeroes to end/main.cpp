#include <bits/stdc++.h>
using namespace std;

void moveZeroes1(vector<int>& num);
void moveZeroes2(vector<int>& num);

int main()
{
    vector<int> num {1,0,2,0,0,0,0,3,12,0,-133,0};
    //moveZeroes1(num);
    moveZeroes2(num);
    for(int i = 0; i < num.size(); i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
}

//my approach
//time: O(n)
//space: O(1)
void moveZeroes1(vector<int>& num) {
    int j = 0;
    for(int i = 0; i < num.size(); i++)
    {
        if(num[i] != 0)
        {
            num[j] = num[i];
            j++;
        }
    }
    for(int i = j; i < num.size(); i++)
    {
        num[i] = 0;
    }
}

//strivers approach
//time: O(n)
//space: O(1)
void moveZeroes2(vector<int>& num)
{
    int j = -1;
    for(int i = 0; i < num.size(); i++)
    {
        if(num[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1) return;

    for(int i = j + 1; i < num.size(); i++)
    {
        if(num[i] != 0)
        {
            swap(num[i], num[j]);
            j++;
        }
    }
}