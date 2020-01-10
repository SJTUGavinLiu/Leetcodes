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
    vector<vector<int>> res;
    vector<int> tmp;
public:
    void helper(TreeNode* root, int cur, int sum)
    {
        if(root && !root->left && !root->right && (cur + root->val) == sum)
        {
            tmp.push_back(root->val);
            res.push_back(tmp);
            tmp.pop_back();
        }
        if(!root)   return;
        tmp.push_back(root->val);
        helper(root->left, cur+root->val,sum);
        helper(root->right, cur+root->val,sum);
        tmp.pop_back();
        

    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)   return {};
        helper(root, 0, sum);
        return res;
    }
};




