#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() <= 2 || nums.front() > 0 || nums.back() < 0) return {};
        vector<vector<int>> res;
        int cur;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1])   continue;//避免重复
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k)
            {
                cur = nums[i] + nums[j] + nums[k];
                if(cur == 0)
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;k--;
                    while(nums[j-1] == nums[j]){
                        j++;
                        if(j >= nums.size())    break;
                    }
                    while(nums[k+1] == nums[k]){
                        k--;
                        if(k < 0)   break;
                    } 
                } 
                else if(cur > 0)
                {
                    k--;
                    while(nums[k+1] == nums[k]){
                        k--;
                        if(k < 0)   break;
                    } 
                }
                else
                {
                    j++;
                    while(nums[j-1] == nums[j]){
                        j++;
                        if(j >= nums.size())    break;
                    }
                }

            }
        }
        return res;
    }
};