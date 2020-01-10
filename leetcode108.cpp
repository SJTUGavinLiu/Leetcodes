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
    TreeNode* helper(vector<int>& nums, int beg, int end)
    {
        if(beg > end)   return NULL;
        TreeNode* tmp;
        if(beg == end)
        {
            tmp = new TreeNode(nums[beg]);
        }
        else
        {
            int mid = (beg+end)/2;
            tmp = new TreeNode(nums[mid]);
            tmp->left = helper(nums,beg,mid-1);
            tmp->right = helper(nums,mid+1,end);
        }
        return tmp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};