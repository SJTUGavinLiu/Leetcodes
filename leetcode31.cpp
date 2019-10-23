#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        for(; i >= 1; i--)
        {
            if(nums[i] <= nums[i-1])    continue;
            else
            {
                int j = i + 1;
                for(; j < nums.size(); j++)
                {
                    if(nums[j] > nums[i-1]) continue;
                    else    break;
                }
                swap(nums[i-1],nums[j-1]);
                reverse(nums.begin()+i,nums.end());
                break;

            }
            
        }
        if(i == 0)
            reverse(nums.begin(),nums.end());
    }
};