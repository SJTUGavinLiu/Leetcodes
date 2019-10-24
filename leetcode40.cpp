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
        if(target == 0)
        {
            result.push_back(tmp);
        }
        for(int i = beg; i < candidates.size();)
        {
            if(target >= candidates[i]) 
            {
                int j = i + 1;
                int k = 1;
                while(j < candidates.size() && candidates[j] == candidates[j-1]) j++;
                for(k = 1; k <= j - i; k++)
                {
                    if(k * candidates[i] <= target)
                    {
                        tmp.push_back(candidates[i]);
                        searcher(candidates,target - k * candidates[i],j);
                    }
                    else
                    {
                        break;
                    }
                }                   
                while(k-1)
                {
                    tmp.pop_back();
                    k--;
                }
                
                i = j;
      
            }
            else
            {
                break;
            }
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        searcher(candidates,target,0);
        return result;
    }
};