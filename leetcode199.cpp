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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)   return {};
        queue<TreeNode*> qu1;
        queue<TreeNode*> qu2;
        vector<int> res;
        qu1.push(root);
        while(!qu1.empty())
        {
            while(!qu1.empty())
            {
                TreeNode* cur = qu1.front();
                qu1.pop();
                if(qu1.empty()) res.push_back(cur->val);
                if(cur->left)  qu2.push(cur->left);
                if(cur->right) qu2.push(cur->right);
            }
            swap(qu2,qu1);
        }
        return res;
    }
    
};