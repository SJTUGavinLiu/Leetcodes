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
    bool flag = 0, first = 0;
    //int res = INT_MIN;
    TreeNode* target;
    TreeNode* res;
    void helper(TreeNode* root)
    {
        if(!root)   return;
        helper(root->left);
        if(flag == 1)
        {
            if(!first)
            {
                res = root;
                first = 1;
            }
            return;
        }
        if(root == target)
            flag = 1;
        helper(root->right);
    }
public:

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root)   return NULL;
        res = NULL;
        target = p;
        helper(root);
        return res;
    }
};