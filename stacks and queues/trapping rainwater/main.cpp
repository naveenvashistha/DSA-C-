
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height); 

int main()
{
    vector<int> n = {4,2,1};
    cout << trap(n) << endl;
}

//My solution
//time: O(n^2)
//space: O(n)
int trap(vector<int>& height) {
    int current_big = -1;
    int water = 0;
    int count = 0;
    stack<int> h;
    for(auto i: height)
    {
        if(h.empty() || i <= h.top()){
            if(h.empty()) current_big = i;
            h.push(i);
        }
        else if(current_big == h.top() && i >= h.top())
        {
            while(!h.empty()) h.pop();
            current_big = i;
            h.push(i);
        }
        else if(i > h.top() && current_big > i)
        {
            while(i > h.top()){
                water += (i - h.top());
                h.pop();
                count++;
            }
            cout << count << " ";
            while(count)
            {
                h.push(i);
                count = count - 1;
            }
            h.push(i);
        }
        else if(i >= current_big)
        {
            while(!h.empty())
            {
                water += (current_big - h.top());
                h.pop();
            }
            current_big = i;
            h.push(i);
        }
        cout << i << " " << water << " " << current_big << endl;
    }
    return water;
}

//better solution
//time: O(n)
//space: O(n)
int trap1(vector<int>& height)
{
    int water = 0;
    int prefix[height.size()];
    int suffix[height.size()];

    prefix[0] = height[0];
    for(int i = 1; i < height.size(); i++)
        prefix[i] = max(prefix[i - 1], height[i]);

    suffix[height.size() - 1] = height[height.size() - 1];
    for(int i = height.size() - 2; i >= 0; i--)
        suffix[i] = max(suffix[i + 1], height[i]);
    
    for(int i = 0; i < height.size(); i++)
        water += min(prefix[i], suffix[i]) - height[i];
    
    return water;
}

//orgasmic(two pointer)
//time: O(n)
//space: O(1)
int trap2(vector<int>& height)
{
    int l = 0;
    int r = height.size() - 1;
    int leftmax = 0;
    int rightmax = 0;
    int  water = 0;

    while(l <= r)
    {
        if(height[l] <= height[r])
        {
            if(height[l] >= leftmax) leftmax = height[l];
            else water += leftmax - height[l];
            l++;
        }
        else
        {
            if(height[r] >= rightmax) rightmax = height[r];
            else water += rightmax - height[r];
            r--;
        }
        return water;
    }
}