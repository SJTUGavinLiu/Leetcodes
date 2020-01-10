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
    int helper(TreeNode* root)
    {
        if(!root)   return INT_MAX;
        if(!root->left && !root->right) return 1;
        return 1 + min(helper(root->left),helper(root->right));
    }
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        else
            return helper(root);
    }
};