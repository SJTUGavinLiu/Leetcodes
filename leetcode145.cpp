/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct NewNode {
    TreeNode *node;
    bool cnt;
    NewNode(TreeNode* n) : node(n), cnt(false) {}
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)   return {};
        NewNode* newRoot = new NewNode(root);
        stack<NewNode*> st;
        vector<int> res;
        st.push(newRoot);

        while(!st.empty())
        {
            NewNode* cur = st.top();
            st.pop();
            if(!cur->cnt)
            {
                cur->cnt = true;
                st.push(cur);
                if(cur->node->right)
                    st.push(new NewNode(cur->node->right));
                if(cur->node->left)
                    st.push(new NewNode(cur->node->left));
            }
            else
            {
                res.push_back(cur->node->val);
            }


        }
        return res;
    }
};