class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())    return 0;
        if(nums.size() == 1)    return nums[0];
        if(nums.size() == 2)    return max(nums[0], nums[1]);
        int first = nums[0];
        int second = nums[1];
        int third = nums[2] + nums[0];

        for(int i = 3; i < nums.size(); i++)
        {
            int tmp = third;
            third = max(first, second) + nums[i];
            first = second;
            second = tmp;
        }
        return max(first, max(second, third));
    }
};