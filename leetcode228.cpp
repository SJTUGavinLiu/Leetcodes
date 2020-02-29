class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0;
        vector<string> res;
        while(i < nums.size())
        {
            int beg = i;
            i++;
            while(i < nums.size())
            {
                if(nums[i-1] + 1 != nums[i])
                    break;
                i++;
            }
            if(beg == i - 1)
                res.push_back(to_string(nums[beg]));
            else
                res.push_back(to_string(nums[beg]) + "->" + to_string(nums[i-1]));
        }
        return res;
    }
};