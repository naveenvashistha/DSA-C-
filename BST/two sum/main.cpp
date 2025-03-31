#include <bits/stdc++.h>

using namespace std;

//better
//save inorder and do two pointer approach
//time: O(n)
//space: O(n)

//optimal
//time: O(n)
//space: O(h)
int next(stack<TreeNode*>& st)
{
    int ans = st.top()->val;
    TreeNode* temp = st.top()->right;
    st.pop();
    while(temp){
        st.push(temp);
        temp = temp->left;
    }
    return ans;
}
int before(stack<TreeNode*>& st)
{
    int ans = st.top()->val;
    TreeNode* temp = st.top()->left;
    st.pop();
    while(temp){
        st.push(temp);
        temp = temp->right;
    }
    return ans;
}
bool findTarget(TreeNode* root, int k) {
    TreeNode* root1 = root;
    TreeNode* root2 = root;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;

    while(root1){
        st1.push(root1);
        root1 = root1->left;
    }

    while(root2){
        st2.push(root2);
        root2 = root2->right;
    }

    int p = next(st1);
    int q = before(st2);
    while(p != q)
    {
        if(p + q == k) return true;
        else if(p + q > k) q = before(st2);
        else p = next(st1);
    }
    return false;
}