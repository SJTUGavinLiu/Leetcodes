class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for(int i = 0 ; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[i] < nums[j])
                    dp[j]++;
                else if(nums[i] > nums[j])
                    dp[i]++;
            }
        }
        return dp;
    }
};