class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int res = 0;
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);
        int tmp = 1;
        for(int k = 0; k < nums.size(); i++)
        {
            if(nums[k] % 2 == 0)    tmp++;
            else
            {
                left[k] = tmp;
                tmp = 1;
            }
        }
        tmp = 1;
        for(int k = nums.size() - 1; k >= 0; k--)
        {
            if(nums[k] % 2 == 0)    tmp++;
            else
            {
                right[k] = tmp;
                tmp = 1;
            }
        }

        int cnt = 1;
        int i = 0;
        int j = 0;
        while(nums[i] % 2 == 0) i++;
        j = i;

        while(j < nums.size())
        {
            if(cnt == k)
            {
                res += (left[i] * right[j]);
                i++;
                while(i <= j && nums[i] % 2 == 0)
                    i++;
                cnt--;
            }
            if(nums[++j] % 2 == 1)
                cnt++;
        }
        return res;

    }
};