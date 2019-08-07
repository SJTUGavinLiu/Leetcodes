#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
        int cnt = 0;
        for(auto &num: nums)
        {
            if(num != val)
                nums[cnt++] == num;
        }
    }
};