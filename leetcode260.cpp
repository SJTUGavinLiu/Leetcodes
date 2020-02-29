class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int mask = 0;
        for(auto& num: nums)
            mask ^= num;
        
        int mask_ = mask & -mask;

        int x = 0;
        for(auto& num: nums)
        {
            if(mask_ & num)
                x ^= num;
        }
        return {x, x ^ mask};

    }
};