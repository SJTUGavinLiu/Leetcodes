#include<vector>
#include<algorithm>
using namespace std;


class Solution {
private:
    vector<vector<int>> result;
    vector<int> tmp;
public:
    void searcher(vector<int>& candidates,int target,int beg)
    {
        for(int i = beg; i < candidates.size(); i++)
        {
            if(target == candidates[i])
            {
                tmp.push_back(candidates[i]);
                result.push_back(tmp);
                tmp.pop_back();
            }
            else if(target > candidates[i]) 
            {
                tmp.push_back(candidates[i]);
                searcher(candidates,target - candidates[i],i);
                tmp.pop_back();
            }
            else
            {
                break;
            }
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        searcher(candidates,target,0);
        return result;
    }
};


/*
class Solution{
public:

    vector<vector<int>> helper(vector<int>& candidates, int end, int target)
    {   
        vector<vector<int>> result = {};
        if(end == 0)
        {
            
            if((target % candidates[0]) == 0)
            {
                result.push_back({});
                for(int i = 0; i< target / candidates[0]; i++)
                {
                    result[0].push_back(candidates[0]);
                }
            }
            return result;
        }
        
        
        int i = 1;
        while(i * candidates[end] <= target)
        {
            for(auto& set: helper(candidates,end-1,target-i*candidates[end]))
            {
                for(int j = 0; j < i; j++)
                {
                    set.push_back(candidates[end]);
                }
                result.push_back(set);
            }
        }
        return result;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        // vector<vector<int>> dp(candidates.size(),vector<int>(target+1,0));
        // dp[i][j] means that use 0~i candiate to achieve the target.
        sort(candidates.begin(),candidates.end());

        return helper(candidates,candidates.size()-1,target);

    }

};
*/