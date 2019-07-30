#include<iostream>
#include<vector>
#include<unordered_map>




using namespace std;
using namespace std::tr1;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> a(2,0);
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)
        {
            int complement = target - nums[i];
            if(map.find(complement)!=map.end())
            {
                a[1]=i;
                a[0]=map[complement];
                return a;
            }
            map[nums[i]]=i;
            
        }
        return a;
    }
};