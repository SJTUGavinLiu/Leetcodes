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
private:
    int res;
public:
    bool helper(TreeNode* root)
    {
        if(!root)   return true;
        bool f1 = helper(root->left);
        bool f2 = helper(root->right);
        if(f1 && f2 && (!root->left || root->left->val == root->val) && (!root->right || root->right->val == root->val))
        {
            res++;
            return true;
        }
        return false;
    }   
    int countUnivalSubtrees(TreeNode* root) {
        res = 0;
        helper(root);
        return res;
    }
};