#include <bits/stdc++.h>

using namespace std;



//space: O(h)
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        int ans = st.top()->val;
        TreeNode* temp = st.top()->right;
        st.pop();
        while(temp){
            st.push(temp);
            temp = temp->left;
        }
        return ans;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};