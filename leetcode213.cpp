class Solution {
public:
    int helper(vector<int>& nums, int beg, int end) {
        if(beg > end)   return 0;
        if(beg == end)  return nums[beg];
        if((end - beg) == 1)    return max(nums[beg], nums[end]);
        int first = nums[beg];
        int second = nums[beg+1];
        int third = nums[beg+2] + nums[beg];

        for(int i = beg+3; i <= end; i++)
        {
            int tmp = third;
            third = max(first, second) + nums[i];
            first = second;
            second = tmp;
        }
        return max(first, max(second, third));
    }
    int rob(vector<int>& nums) {
        if(nums.empty())    return 0;
        if(nums.size() == 1)    return nums[0];
        if(nums.size() == 2)    return max(nums[0], nums[1]);

        int n = nums.size();
        int res = nums[0] + helper(nums, 2,n-2);
        res = max(res, nums[1] + helper(nums, 3,n-1));
        res = max(res, nums[2] + helper(nums, 4,n-1));


    }
};