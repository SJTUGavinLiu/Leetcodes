

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        int Max = nums[0];
        int tmp = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(tmp >= 0)    tmp += nums[i];
            else    tmp = nums[i];
            Max = Max > tmp ? Max : tmp;
        }
        return Max;
    }
}