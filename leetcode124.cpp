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
    int Max = INT_MIN;
public:
    int helper(TreeNode* root)
    {
        if(!root)   return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        Max = max(max(0,left) + max(0,right) + root->val,Max);
        return root->val + max(max(left,right), 0);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return Max;
    }
};