//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

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

//orgasmic
//time: O(n*m)
//space: O(n)
int maximalRectangle(vector<vector<char>>& matrix) {
    vector<int> heights(matrix[0].size());
    int area_max = INT_MIN;
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            if(matrix[i][j] == '1') heights[j] += 1;
            else heights[j] = 0;
        }
        area_max = max(area_max, largestRectangleArea(heights));
    }
    return area_max;
}

int main()
{
    vector<vector<char>> heights = {{'1', '0', '1', '1'}, {'1', '0', '1', '1'}};
	cout << maximalRectangle(heights) << endl;
}
