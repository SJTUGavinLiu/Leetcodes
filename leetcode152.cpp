class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dp;
        int res = nums[0];
        int i = 0;
        while(i < nums.size())
        {
            
            while(i < nums.size() && nums[i] == 0)
                i++;
            int j = i;    
            int cnt = 1;
            while(j < nums.size() && nums[j] != 0)
            {
                cnt *= nums[j];
                res = max(res, cnt);
                j++;
            }
            if(j < nums.size())
                res = max(res, 0);
            
            int tmp = i;
            i = j;
            j--;
            cnt = 1;
            while(j >= tmp)
            {
                cnt *= nums[j];
                res = max(res, cnt);
                j--;
            }
        }
        return res;
    }
};