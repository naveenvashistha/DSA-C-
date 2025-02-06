//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

//brute
//time: O(n^2)
//space: O(1)
int largestRectangleArea(vector<int>& heights) {
    int area_max = INT_MIN;
    for(int i = 0; i < heights.size(); i++)
    {
        int minn = INT_MAX;
        int steps = 1;
        for(int j = i; j >= 0; j--)
        {
            minn = min(heights[j], minn);
            int area = steps * minn;
            steps++;
            if(area > area_max)
                area_max = area;
        }
    }
    return area_max;
}

//orgasmic
//time: O(n)
//space: O(1)
int largestRectangleArea(vector<int>& heights) {
    vector<int> nse(heights.size(), heights.size());
    vector<int> pse(heights.size(), -1);
    stack<int> st1, st2;
    for(int i = heights.size() - 1; i >= 0; i--)
    {
        while(!st1.empty() && heights[st1.top()] >= heights[i])
            st1.pop();
        if(!st1.empty()) nse[i] = st1.top();
        st1.push(i);
    }

    for(int i = 0; i < heights.size(); i++)
    {
        while(!st2.empty() && heights[st2.top()] >= heights[i])
            st2.pop();
        if(!st2.empty()) pse[i] = st2.top();
        st2.push(i);
    }
    int area_max = INT_MIN;
    for(int i = 0; i < heights.size(); i++)
    {
        int area = max((nse[i] - pse[i] - 1) * heights[i], max((i - pse[i]) * heights[i], (nse[i] - i) * heights[i]));
        area_max = max(area, area_max);
    }

    return area_max;
}


int main()
{
    vector<int> heights = {2,1,4,6,5};
	cout << largestRectangleArea(heights) << endl;
}
