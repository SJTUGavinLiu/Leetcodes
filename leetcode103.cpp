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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)   return {};
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        st1.push(root);
        TreeNode* cur;
        vector<int> line;
        vector<vector<int>> res;
        while(!st1.empty())
        {
            while(!st1.empty())
            {
                cur = st1.top();
                if(cur->left)   st2.push(cur->left);
                if(cur->right)  st2.push(cur->right);
                line.push_back(cur->val);
                st1.pop();       
            }
            if(!line.empty())
            {
                res.push_back(line);
                line.clear();
            }
            while(!st2.empty())
            {
                cur = st2.top();
                if(cur->right)   st1.push(cur->right);
                if(cur->left)  st1.push(cur->left);
                line.push_back(cur->val);
                st2.pop();
            }
            if(!line.empty())
            {
                res.push_back(line);
                line.clear();
            }
        }

        return res;   

    }
};