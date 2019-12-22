class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) 
            return 0;
        int sum = 0;
        int pre = nums[0] + 1;
        int size = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(pre != nums[i])
            {
                pre = nums[i];
                sum = 0;
                nums[size++] = pre;
                continue;
            }
            if(sum >= 0)
                nums[size++] = pre;
            
            sum--;
        }
        return size;
    }
};