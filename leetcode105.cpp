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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int beg1, int end1, int beg2, int end2)
    {
        TreeNode* root = new TreeNode(preorder[beg1]);

        if(beg1 == end1)
            return  root;
        for(int i = beg2; i <= end2; i++)
        {
            if(inorder[i] == preorder[beg1])
            {
                if(i == beg2) root->right = helper(preorder, inorder, beg1+1, end1,beg2+1,end2);
                else if(i == end2)  root->left = helper(preorder, inorder,beg1+1,end1,beg2,end2-1);
                else
                {
                    int len1 = i-beg2;
                    int len2 = end2-i;
                    root->left = helper(preorder, inorder, beg1+1, beg1+len1,beg2,i-1);
                    root->right = helper(preorder, inorder, beg1+len1+1, end1,i+1,end2);
                    break;
                }

            }
        }

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())
            return NULL;
        return helper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};