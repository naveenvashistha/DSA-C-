#include <bits/stdc++.h>

using namespace std;

//time: O(n)
//space: O(n)
int candy(vector<int>& ratings) {
    vector<int> left(ratings.size(), 1);
    int sum = 0;
    for(int i = 1; i < left.size(); i++)
    {
        if(ratings[i - 1] < ratings[i]) left[i] = left[i - 1] + 1;
    }
    for(int i = left.size() - 2; i >= 0; i--)
    {
        if(ratings[i] > ratings[i + 1])
        {
            left[i] = max(left[i], left[i + 1] + 1);
        }
        sum += left[i];
    }
    return sum + left[left.size() - 1];
}

//orgasmic
//time: O(n)
//space: O(1)
int candy(vector<int>& ratings) {
    int sum = 1;
    int i = 1;
    while(i < ratings.size())
    {
        if(ratings[i] == ratings[i - 1])
        {
            sum++;
            i++;
        }
        else
        {
            int c = 1;
            while(i < ratings.size() && ratings[i] > ratings[i - 1])
            {
                c++;
                sum += c;
                i++;
            }
            int peak = c;
            c = 0;
            while(i < ratings.size() && ratings[i] < ratings[i - 1])
            {
                c++;
                sum += c;
                i++;
            }
            if(c >= peak) sum += (c + 1 - peak);
        }
    }
    return sum;
}


int main()
{
}

