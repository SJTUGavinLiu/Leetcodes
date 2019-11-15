#include<vector>
#include<algorithm>
class Solution {
public:
    vector<vector<int>> helper(vector<int> &nums,int beg, int end)
    {
        
        if(beg == end)  return {{nums[beg]}};
        else{
            vector<vector<int>> res;
            for(int i = end; i >= beg; i--)
            {
                swap(nums[end],nums[i]);
                for(auto& item: helper(nums, beg, end-1))
                {
                    item.push_back(nums[end]);
                    res.push_back(item);
                }
                swap(nums[end],nums[i]);
                while(i > 0 && nums[i-1] == nums[i])
                    i--;
            }
            return res;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0)    return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        return helper(nums,0,nums.size()-1);
    }
};