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
    vector<int> arr;
    void inOrder(TreeNode* root)
    {
        if(!root)   return ;
        inOrder(root->left);
        arr.push_back(root->val);
        inOrder(root->right);
    }
    int divide(vector<int>& arr, int l, int r, float target)
    {
        
        if(l > r)   return -1;
        if(l == r)  return l;
        int mid = (l + r) / 2;
        float cur = target - float(arr[mid]);
        int idx;
        
        //cout <<l << '\t' << r << '\t' << arr[mid] << '\t' << cur << endl;
        if(cur > 0)
            idx = divide(arr, mid+1, r, target);
        else
            idx = divide(arr, l, mid-1, target);
        if(idx == -1)
            return mid;
        if(abs(cur) < abs(float(arr[idx]) - target))
            return mid;
        return idx;
        
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        if(k == 0)
            return {};
        inOrder(root);
        int len = arr.size();
        int i = divide(arr, 0, len-1, target);
        //cout << i << '\t' << arr[i];
        int j = i;
        k--;
        vector<int> res;
        res.push_back(arr[i]);
        while(k)
        {
            if(i == 0)
            {
                j++;
                res.push_back(arr[j]);
            }
            else if(j == len - 1)
            {
                i--;
                res.push_back(arr[i]);
            }
            else
            {
                if(abs(float(arr[i-1]) - target) > abs(float(arr[j+1]) - target))
                {
                    j++;
                    res.push_back(arr[j]); 
                }
                else
                {
                    i--;
                    res.push_back(arr[i]);                   
                }
            }
            k--;
        }

        return res;
        
    }
};