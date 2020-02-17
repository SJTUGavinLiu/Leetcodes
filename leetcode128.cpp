
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())    return 0;
        unordered_map<int, int> dict;
        int left, right, curLen;
        int maxLen = 1;


        for(auto& num: nums)
        {
            if(!dict.count(num))
            {
                left = dict.count(num-1) ? dict[num-1] : 0;
                right = dict.count(num+1) ? dict[num+1] : 0;
                
                curLen = left + right + 1;
                maxLen = maxLen > curLen ? maxLen : curLen;

                dict[num] = curLen; // take the place
                dict[num - left] = curLen;
                dict[num + right] = curLen;
            }
        }
        return maxLen;

    }
};