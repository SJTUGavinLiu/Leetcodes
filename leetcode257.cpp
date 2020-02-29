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
    vector<string> res;
    void dfs(string s, TreeNode* root)
    {
        string cur = s + "->" + to_string(root->val);
        if(!root->left && !root->right)
        {
            res.push_back(cur);
            return;
        }

        if(root->left)  dfs(cur, root->left);
        if(root->right) dfs(cur, root->right);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)   return res;
        if(!root->left && !root->right) return { to_string(root->val) };
        if(root->left)  dfs(to_string(root->val), root->left);
        if(root->right) dfs(to_string(root->val), root->right);
        return res;
    }
};