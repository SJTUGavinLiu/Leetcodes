#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())    return 0;
        int pre = nums[0];
        int cnt = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == pre)
                continue;
            else
            {
                pre = nums[i];
                nums[cnt++] = pre;
            }
        }
        return cnt;
    }
};