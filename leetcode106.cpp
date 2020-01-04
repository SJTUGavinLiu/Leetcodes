class Solution {
public:
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder, int beg1, int end1, int beg2, int end2)
    {
        TreeNode* root = new TreeNode(postorder[end1]);

        if(beg1 == end1)
            return  root;
        for(int i = beg2; i <= end2; i++)
        {
            if(inorder[i] == postorder[end1])
            {
                if(i == beg2) root->right = helper(postorder, inorder, beg1, end1-1,beg2+1,end2);
                else if(i == end2)  root->left = helper(postorder, inorder,beg1,end1-1,beg2,end2-1);
                else
                {
                    int len1 = i-beg2;
                    int len2 = end2-i;
                    root->left = helper(postorder, inorder, beg1, beg1+len1-1,beg2,i-1);
                    root->right = helper(postorder, inorder, beg1+len1, end1-1,i+1,end2);
                    break;
                }

            }
        }

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty())
            return NULL;
        return helper(postorder,inorder,0,postorder.size()-1,0,inorder.size()-1);
    }
};