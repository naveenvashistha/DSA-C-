#include <bits/stdc++.h>

using namespace std;

//time: O(n)
//space: O(n)
void traversal(Node* node, vector<vector<int>>& ans, vector<int>& temp)
{
    if(node == NULL) return;
    temp.push_back(node->data);
    if(!node->left && !node->right) ans.push_back(temp);
    traversal(node->left, ans, temp);
    if(node->left != NULL) temp.pop_back(); 
    traversal(node->right, ans, temp);
    if(node->right != NULL) temp.pop_back();
}
vector<vector<int>> Paths(Node* root) {
    // code here
    vector<vector<int>> ans;
    vector<int> temp;
    traversal(root, ans, temp);
    return ans;
}