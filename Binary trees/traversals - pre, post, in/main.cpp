#include <bits/stdc++.h>

using namespace std;


class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

//time: O(n)
//space: O(n)
void preorder(TreeNode *root, vector<int> &pre)
{
    if(root == NULL) return;
    pre.push_back(root->data);
    preorder(root->left, pre);
    preorder(root->right, pre);
}
//time: O(n)
//space: O(n)
void postorder(TreeNode *root, vector<int> &post)
{
    if(root == NULL) return;
    postorder(root->left, post);
    postorder(root->right, post);
    post.push_back(root->data);
}
//time: O(n)
//space: O(n)
void inorder(TreeNode *root, vector<int> &ino)
{
    if(root == NULL) return;
    inorder(root->left, ino);
    ino.push_back(root->data);
    inorder(root->right, ino);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int> pre;
    vector<int> post;
    vector<int> ino;
    preorder(root, pre);
    postorder(root, post);
    inorder(root, ino);
    vector<vector<int>> v = {ino, pre, post};
    return v;
}

//iterative approach
//time: O(n)
//space : O(n)
vector<int> preOrder(TreeNode * root){
    // Write your code here.
    stack<TreeNode*> st;
    vector<int> ans;
    if(root == NULL) return ans;
    st.push(root);
    while(!st.empty())
    {
        TreeNode* node = st.top();
        ans.push_back(node->data);
        st.pop();
        if(node->right != NULL) st.push(node->right);
        if(node->left != NULL) st.push(node->left);
    }
    return ans;
}

//iterative approach
//time: O(n)
//space: O(n)
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    stack<TreeNode*> st;
    vector<int> ans;
    st.push(root);
    while(!st.empty())
    {
        TreeNode* node = st.top();
        if(node->left != NULL) st.push(node->left);
        else
        {
            while(true)
            {
                ans.push_back(node->data);
                st.pop();
                if(node->right != NULL){
                    st.push(node->right);
                    break;
                }
                if(!st.empty()) node = st.top();
                else break;
            }
        }
    }
    return ans;
}

//iterative approach (preferred)
//time: O(n)
//space: O(n)
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    stack<TreeNode*> st;
    vector<int> ans;
    TreeNode* node = root;
    while(true)
    {
        if(node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            node = st.top();
            node = node->right;
        }
    }
    return ans;
}

//iterative approach using two stacks
//time: O(n)
//space: O(n)
vector<int> postorderTraversal(TreeNode *root)
{
    // Write your code here.
    stack<TreeNode*> st;
    st.push(root);
    stack<int> s;
    vector<int> ans;
    while(!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        if(node->left != NULL) st.push(node->left);
        if(node->right != NULL) st.push(node->right);
        s.push(node->data);
    }
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

//iterative approach using one stacks
//time: O(n)
//space: O(n)
vector<int> postOrder(TreeNode* root) {
    // code here
    stack<TreeNode*> st;
    vector<int> ans;
    TreeNode* nod = root;
    while(nod != NULL || !st.empty())
    {
        if(nod != NULL)
        {
            st.push(nod);
            nod = nod->left;
        }
        else
        {
            TreeNode* temp = st.top()->right;
            if(temp == NULL)
            {
                temp = st.top();
                ans.push_back(temp->data);
                st.pop();
                while(!st.empty() && st.top()->right == temp)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
            {
                nod = temp;
            }
        }
    }
    return ans;
}

//recursive (one traversal for pre, post and in)
//time: O(n)
//space: O(n)
void order(TreeNode *root, vector<int> &pre, vector<int> &post, vector<int> &ino)
{
    if(root == NULL) return;
    pre.push_back(root->data);
    order(root->left, pre, post, ino);
    ino.push_back(root->data);
    order(root->right, pre, post, ino);
    post.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int> pre;
    vector<int> post;
    vector<int> ino;
    order(root, pre, post, ino);
    vector<vector<int>> v = {ino, pre, post};
    return v;
}

//iterative (one traversal for pre, post, ino)
//time: O(n)
//space: O(n)
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int> pre;
    vector<int> post;
    vector<int> ino;
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    while(!st.empty())
    {
        pair<TreeNode*, int> temp = st.top();
        st.pop();
        if(temp.second == 1)
        {
            pre.push_back(temp.first->data);
            st.push({temp.first, temp.second + 1});
            if(temp.first->left) st.push({temp.first->left, 1});
        }
        else if(temp.second == 2)
        {
            ino.push_back(temp.first->data);
            st.push({temp.first, temp.second + 1});
            if(temp.first->right) st.push({temp.first->right, 1});
        }
        else
        {
            post.push_back(temp.first->data);
        }
    }
    vector<vector<int>> v = {ino, pre, post};
    return v;
}
