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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* r = root;
        if(p->val > q->val)
            swap(p, q);
        while(r)
        {
            if(r->val >= p->val && r->val <= q->val)
                return r;
            if(r->val < p->val)
                r = r->right;
            else
                r = r->left;
        }
        cout << 1;
        return r;

    }
};