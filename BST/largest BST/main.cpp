#include <bits/stdc++.h>

using namespace std;

//brute
//time: O(n^2)
//space: O(n)
bool validate(Node* node, int& temp, int start, int end)
{
    if(node == NULL) return true;
    if(start < node->data && node->data < end){
        temp++;
        bool res1 = validate(node->left, temp, start, node->data);
        bool res2 = validate(node->right, temp, node->data, end);
        return res1 && res2;
    }
    return false;
}
void largest(Node* node, int& ans)
{
    if(node == NULL) return;
    int temp = 0;
    bool res = validate(node, temp, INT_MIN, INT_MAX);
    if(res) ans = max(ans, temp);
    largest(node->left, ans);
    largest(node->right, ans);
}
int largestBst(Node *root)
{
    //Your code here
    int ans = 1;
    largest(root, ans);
    return ans;
}

//orgasmic
//time: O(n)
//space: O(n)
vector<int> largest(Node* node)
{
    if(node == NULL)
        return {0, INT_MAX, INT_MIN};
    vector<int> v1 = largest(node->left);
    vector<int> v2 = largest(node->right);
    if(v1[2] < node->data && v2[1] > node->data)
        return {1 + v1[0] + v2[0], min(v1[1], node->data), max(v2[2], node->data)};
    return {max(v1[0], v2[0]), INT_MIN, INT_MAX};
}
int largestBst(Node *root)
{
    //Your code here
    vector<int> v = largest(root);
    return v[0];
}