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
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if(!a && !b)   return true;
        if((!a && b) || (a && !b))    return false;
        if(a->val != b->val)
            return false;
        return isSameTree(a->left,b->left) && isSameTree(a->right,b->right);

    }
};