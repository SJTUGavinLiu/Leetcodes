class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root || !root->left)    return root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = NULL;
        root->right = NULL;
        TreeNode* res = upsideDownBinaryTree(left);
        left->left = right;
        left->right = root;
        return res;
    }
};