#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4)   return{};
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if(nums.front()>(target+3)/4 || nums.back()< target/4)  return {};
        int i,j,a,b;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>(target+3)/4)    break;
            if(i>0 && nums[i]==nums[i-1])  continue;
            for(int j=nums.size()-1;j>=(i+3);j--)
            {
                if(nums[j]<target/4)    break;
                if((j+1)<nums.size() && nums[j]==nums[j+1])  continue;   
                a=i+1;
                b=j-1;
                int tar = target-nums[i]-nums[j];
                while(a<b)
                {
                    if(nums[a]+nums[b]==tar)
                    {
                        res.push_back({nums[i],nums[a],nums[b],nums[j]});
                        a++;b--;
                        while(nums[a-1]==nums[a]){
                            a++;
                            if(a >= nums.size())    break;
                        }
                        while(nums[b+1]==nums[b]){
                            b--;
                            if(b < 0)   break;
                        } 
                        
                    }
                    else if((nums[a]+nums[b])>tar)
                    {
                        b--;
                        while(nums[b+1]==nums[b]){
                            b--;
                            if(b < 0)   break;
                        } 
                    }
                    else
                    {
                        a++;
                        while(nums[a-1]==nums[a]){
                            a++;
                            if(a >= nums.size())    break;
                        }
                    }
                }
            }
        }
        return res;
    }
};