class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len+2, vector<int>(len+2, 0));
        vector<int> nums_(len+2, 1);
        for(int i = 0; i < len; i++)
            nums_[i+1] = nums[i];
        
        for(int i = len-1; i >= 0; i--)
        {
            for(int j = i+2; j <= len + 1; j++)
            {
                for(int k = i+1; k < j; k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums_[i] * nums_[j] * nums_[k]);
                }
            }
        }
        return dp[0][len+1];
    }
};