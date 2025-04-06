#include <bits/stdc++.h>

using namespace std;

//orgasmic
//time: O(mxn)
//space: O(mxn)
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    queue<pair<int, int>> q;
    int org = image[sr][sc];
    if(image[sr][sc] != color){
        q.push({sr, sc});
        image[sr][sc] = color;
    }
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;
        if(i - 1 >= 0 && image[i - 1][j] == org){
            image[i - 1][j] = color;
            q.push({i - 1, j});
        }
        if(j - 1 >= 0 && image[i][j - 1] == org){
            image[i][j - 1] = color;
            q.push({i, j - 1});
        }
        if(i + 1 < image.size() && image[i + 1][j] == org){
            image[i + 1][j] = color;
            q.push({i + 1, j});
        }
        if(j + 1 < image[0].size() && image[i][j + 1] == org){
            image[i][j + 1] = color;
            q.push({i, j + 1});
        }
    }
    return image;
}