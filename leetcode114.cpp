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
    TreeNode* helper(TreeNode* root)
    {
        
        if(!root)   return NULL;
        if(!root->left && !root->right) return root;
        else
        {
            TreeNode* p = helper(root->left);
            TreeNode* q = helper(root->right);
            if(p)
            {
                TreeNode* tmp = root->right;
                root->right = root->left;
                p->right = tmp;
            }

            root->left = NULL;
            if(!q)  return p;
            else  return q;

        }
        return NULL;
        

    }
    void flatten(TreeNode* root) {
        if(!root)   return;
        helper(root);
    }
};

/*

TreeNode* last = nullptr;
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->right);
        flatten(root->left);
        root->right = last;
        root->left = nullptr;
        last = root;
    }
*/