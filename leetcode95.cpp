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
    
public:
    vector<TreeNode*> helper(int x, int y)
    {
        if(y < x)   return {NULL};
        vector<TreeNode*> res;
        for(int i = x; i <= y; i++)
        {
            
            vector<TreeNode*> left = helper(x,i-1);
            vector<TreeNode*> right = helper(i+1,y);
            for(auto l: left)
            {
                for(auto r: right)
                {
                    TreeNode* new_root = new TreeNode(i+1);
                    new_root->left = l;
                    new_root->right = r;
                    res.push_back(new_root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)  return {};
        return helper(0, n-1);
    }
};