/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*>  st;
        st.push(root);
        vector<int> res;
        while(!st.empty())
        {
            TreeNode* cur = st.top();
            st.pop();
            if(cur->right)  st.push(cur->right);
            if(cur->left)   st.push(cur->left);
            res.push_back(cur->val);   
        }
        return res;
    }
};