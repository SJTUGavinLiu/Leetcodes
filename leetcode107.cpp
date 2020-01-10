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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)   return {};
        queue<TreeNode*> qu;
        qu.push(root);
        TreeNode* end = root;
        vector<int> line;
        vector<vector<int>> res;

        TreeNode* cur;
        int layer = 1;
        while(!qu.empty())
        {
            cur = qu.front();
            line.push_back(cur->val);
            
            if(cur == end)
            {
                
                if(cur->left)   qu.push(cur->left);
                if(cur->right)  qu.push(cur->right);
                res.push_back(line);
                line.clear();
                qu.pop();
                if(qu.empty())  break;
                end = qu.back();
                continue;
            }
            else
            {
                if(cur->left)   qu.push(cur->left);
                if(cur->right)  qu.push(cur->right);
                qu.pop();
            }
            
        }
        if(!line.empty())   res.push_back(line);
        reverse(res.begin(), res.end());
        return res;
    }
};