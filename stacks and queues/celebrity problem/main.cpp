//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

//brute
//time: O(n^2)
//space: O(n)
int celebrity(vector<vector<int> >& mat) {
    // code here
    vector<pair<int, int>> record(mat.size());
    for(int i = 0; i < mat.size(); i++)
    {
        for(int j = 0; j < mat[0].size(); j++)
        {
            if(mat[i][j] == 1)
            {
                record[i].first++;
                record[j].second++;
            }
        }
    }
    
    for(int i = 0; i < mat.size(); i++)
    {
        if(record[i].first == 0 && record[i].second == mat.size() - 1)
            return i;
    }
    return -1;
}

//orgasmic
//time: O(2n)
//space: O(1)
int celebrity(vector<vector<int> >& mat) {
    // code here
    int top = 0, down = mat.size() - 1;
    while(top != down)
    {
        if(mat[top][down] == 1) top++;
        else if(mat[down][top] == 1) down--;
        else{
            top++;
            down--;
        }
    }
    for(int i = 0; i < mat.size(); i++)
    {
        if(mat[top][i] != 0) return -1;
        if(i != top && mat[i][top] != 1 ) return -1;
    }
    return top;
}

int main()
{
    vector<vector<int>> people = {{1,0,1}, {1,0,0}, {0,1,1}};
	cout << celebrity(people) << endl;
}
