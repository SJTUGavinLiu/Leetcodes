class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {


        if(nums.empty())
        {
            if(lower == upper)
                return { to_string(lower) };
            else
                return {to_string(lower) + "->" + to_string(upper)};
        }
        long long beg = lower;
        vector<string> res;
        for(long long num:nums)
        {
            if(beg > num)
            {
                continue;
            }
            else if(num == beg)
            {
                beg = num+1;
            }
            else if(num == (beg+1))
            {
                res.push_back(to_string(beg));
                beg = num+1;
            }
            else
            {
                res.push_back(to_string(beg) + "->" + to_string(num-1));
                beg = num + 1;
            }
            

        }
        if(beg > upper)
            return res;
        else if(beg == upper)
        {
            res.push_back(to_string(beg));
        }
        else
        {
            res.push_back(to_string(beg) + "->" + to_string(upper));
        }
        return res;

    }
};