class Solution {
private:
    vector<int> tmp;     
    vector<vector<int>> res;
    int N;      
public:
    void backtrack(int step,vector<int>& nums)
    {
        if(step == N)
            res.push_back(tmp);
        else
        {            
            backtrack(step+1, nums);
            tmp.push_back(nums[step]);
            backtrack(step+1, nums);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        N = nums.size();
        backtrack(0, nums);
        return res;
    }
};