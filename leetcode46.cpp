#include<vector>
#include<algorithm>







/* Recurrence */

class Solution1 {
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
            }
            return res;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0)    return {{}};
        vector<vector<int>> res;
        return helper(nums,0,nums.size()-1);
    }
};


class Solution2 {
private:
    vector<int> occupied;
    vector<int> tmp;
    vector<vector<int>> res;
public:
    void helper(vector<int>& nums, int cur)
    {
        if(cur == nums.size())
        {
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(!occupied[i])
            {
                occupied[i] = true;
                tmp[cur] = nums[i];
                helper(nums,cur+1);
                occupied[i] = false;
            }

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            occupied.push_back(false);
            tmp.push_back(0);
        }
        helper(nums, 0);
        return res;

        
    }
};