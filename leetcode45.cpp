#include<vector>
#include<string>
#include<limits.h>
#include<unordered_map>

using namespace std;



/* Dynamic Programming */
/*
class Solution {
public:
    
    int jump(vector<int>& nums) {
        unordered_map<int,int> map;
        int steps = 0;  // the largest number of steps we take till now.
        map[0] = nums.size() - 1;
        int cur = 0;
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            int range = i + nums[i];
            //int j = i + nums[i] > nums.size() - 1 ? nums.size() - 1 : i + nums[i]
            for(int j = 0; j <= steps; j++)
            {
                if(range >= map[j])
                {
                    cur = j + 1;
                    printf("%d\n",cur);
                    map[cur] = i;
                    if(cur > steps) {
                        steps ++; 
                    }
                    break;
                }
            }
            
        }
        return cur;
    }
};

*/

/* Greedy */
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int border = 0;
        int Max = 0;
        int steps = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            Max = max(Max, nums[i] + i);
            if(i == border)
            {
                steps++;
                border = Max;
            }
        }
        return steps;
    }
};





int main()
{
    vector<int> nums = {2,3,1,1,4};
    Solution obj;
    printf("%d", obj.jump(nums));
    return 0;
}