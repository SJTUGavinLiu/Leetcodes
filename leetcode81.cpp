class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)    return false;
        int beg = 0;
        int end = nums.size()-1;
        while(beg <= end)
        {
            int mid = (beg + end)/2;
            if(target == nums[mid])
                return true;
            if(nums[beg] == nums[mid])
            {
                beg++;
                continue;
            }
            else if(nums[beg] < nums[mid])
                if(nums[beg] <= target && target <= nums[mid])  end = mid - 1;
                else beg = mid + 1;
            else
                if(nums[mid] <= target && target <= nums[end]) beg = mid + 1;
                else end = mid - 1;
                    
        }
        return false;
    }
};