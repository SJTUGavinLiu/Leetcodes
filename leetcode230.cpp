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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>    st;
        TreeNode* p = root;
        while(p)
        {
            st.push(p);
            p = p->left;
        }

        while(!st.empty())
        {
            if(k == 1)  return st.top()->val;
            p = st.top()->right;
            st.pop();
            while(p)
            {
                st.push(p);
                p = p->left;
            }
            k--;
        }
        return 0;
    }
};