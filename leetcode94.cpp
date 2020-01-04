class Solution {
vector<int> res;
public:
    void helper(TreeNode* root)
    {
        if(!root)   return;
        helper(root->left);
        res.push_back(root->val);
        helper(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return res;
    }
};




class Solution {
vector<int> res;
public:

    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)   return {};
        stack<TreeNode*> st;
        vector<int> res;
        st.push(root);
        TreeNode* p = root;
        while(p->left)
        {
            st.push(p->left);
            p = p->left;
        }
        while(!st.empty())
        {
            p = st.top();
            st.pop();
            res.push_back(p->val);
            p = p->right;
            while(p)
            {
                st.push(p);
                p = p->left;
            }
        }
        return res;
    }
};



