
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0,right = 0;
        int len = nums.size();
        int sum = 0;
        int res = INT_MAX;
        while(right < len)
        {
            while(sum < s && right < len)
            {
                sum+=nums[right++];
            }
            while(sum >= s)
            {
                res = min(res, right-left);
                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
