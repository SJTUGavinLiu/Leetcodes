class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())    return false;
        int beg = 0;
        int end = nums.size()-1;
        int mid;
        while(beg <= end)
        {
            
            
            if(nums[beg] < nums[end])
            {
                while(beg <= end)
                {
                    cout << "Second" << beg << " " << end << endl;
                    mid = (beg+end)/2;
                    if(nums[mid] == target)
                        return true;
                    if(nums[mid] == target)
                        return true;
                    if(target < nums[mid])
                        end = mid-1;
                    else
                        beg = mid+1;
                }
                return false;

            }
            else
            {
                cout << "First" << beg << " " << end << endl;
                if(target < nums[beg] && target > nums[end])
                    return false;
                mid = (beg+end)/2;
                if(nums[mid] == target || target == nums[beg] || target == nums[end])
                    return true;

                if(target > nums[beg])
                    end = mid - 1;
                else if(target < nums[end])
                    beg = mid + 1;

            }
        }
        return false;
    }
};