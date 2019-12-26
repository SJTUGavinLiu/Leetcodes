class Solution {
private:
    vector<int> tmp;
    vector<vector<int>> res;
public:
    void Search(int pos, vector<int>& nums)
    {
        if(pos == nums.size())
        {
            res.push_back(tmp);
            return;
        }
           
        //int refer = nums[pos];
        int p = pos;
        while(p != nums.size() && nums[p] == nums[pos])
            p++;
        int len = p - pos;
        for(int i = 0; i < len; i++)
        {
            tmp.push_back(nums[pos]);
            Search(p, nums);
        }
        for(int i = 0; i < len; i++)
        {
            tmp.pop_back();
        }
        Search(p, nums);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        Search(0,nums);
        return res;


    }
};