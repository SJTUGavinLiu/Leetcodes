class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxRange = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(maxRange < i)    return false;
            maxRange = max(maxRange, i+nums[i]); 
        }
        return true;
    }
};