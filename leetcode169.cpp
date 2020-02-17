class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int cur = 0;
        for(auto& num: nums)
        {
            if(cnt == 0)
            {
                cnt++;
                cur = num;
                continue;
            }
            
            if(num == cur)
                cnt++;
            else
                cnt--;
        }
        return cur;
    }
};