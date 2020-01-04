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
    bool isValidBST(TreeNode* root) {
        if(!root)   return true;
        
        stack<TreeNode*> st;
        TreeNode* p = root;
        

        
        while(p)
        {
            st.push(p);
            p = p->left;
        }

        long pre = long(st.top()->val)-1;
        TreeNode* cur;
        while(!st.empty())
        {
            cur = st.top();
            st.pop();
            if(cur->val <= pre)
                return false;
            pre = cur->val;

            p = cur->right;
            while(p)
            {
                st.push(p);
                p = p->left;
            }

        }

        return true;
        


    }
};