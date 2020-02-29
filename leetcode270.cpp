class Solution {
private:
    double Min;
public:
    int closestValue(TreeNode* root, double target) {
        if(!root)   return 0;
        Min = abs(float(root->val) - target);
        int obj = root->val;
        TreeNode* p = root;
        while(p)
        {
            if(abs(float(p->val) - target) < Min)
            {
                obj = p->val;
                Min = abs(float(p->val) - target);
            }
            if(target > float(p->val))
                p = p->right;
            else
                p = p->left;
        }
        return obj;  
    }
};