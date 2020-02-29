class Solution {
private:
    int depth;
    int len;
    TreeNode* r;
    bool isExist(int idx)
    {
        TreeNode* p = r;
        int i = 0;
        int j = len - 1;
        for(int k =0; k < depth; k++)
        {
            int mid = (i + j) / 2;
            if(idx <= mid)
            {
                p = p->left;
                j = mid;
            }
            else
            {
                p = p->right;
                i = mid+1;
            }
        }
        return p ? true : false;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        r = root;
        depth = 0;
        TreeNode* p = root;
        while(p->left)
        {
            p = p->left;
            depth++;
        }
        if(depth == 0)   return 1;
        len = pow(2, depth);
        int left = 1;
        int right = len - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(isExist(mid))
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return pow(2, depth) - 1 + left; 
        


    }
};