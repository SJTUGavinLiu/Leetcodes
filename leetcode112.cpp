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
    bool helper(TreeNode* root, int cur, int sum)
    {
        if(root && !root->left && !root->right && (cur + root->val) == sum) return true;
        if(!root)   return false;
        return helper(root->left, cur+root->val,sum) || helper(root->right, cur+root->val,sum);
        

    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)   return false;
        return helper(root, 0, sum);
    }
};