class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int cnt = 0;
        int mul = 1;
        int pos = -1;
        vector<int> res(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)   
            {
                pos = i;
                cnt++;
                if(cnt == 2)
                    return res;
                continue;
            }
            mul *= nums[i];
        }

        if(cnt == 1)
            res[pos] = mul;
        else
        {
            for(int i = 0; i < nums.size(); i++)
                res[i] = mul / nums[i];
        }

        return res;
    }
};