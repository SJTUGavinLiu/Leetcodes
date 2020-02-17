class Solution {
int res;
public:
    void backtrack(TreeNode* root, int tmp)
    {
        if(!root->left && !root->right)
        {
            res += (tmp * 10 + root->val);
        }
        else
        {
            if(root->left)
                backtrack(root->left, tmp * 10 + root->val);
            if(root->right)
                backtrack(root->right, tmp * 10 + root->val);
        }
        
    }
    int sumNumbers(TreeNode* root) {
        res = 0;
        if(!root) return res;
        backtrack(root, 0);
        return res;

    }
};