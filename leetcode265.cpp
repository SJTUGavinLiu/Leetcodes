class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty())   return 0;
        if(costs[0].size() == 1)    return costs[0][0];
        int k = costs[0].size();
        vector<int> cur(k, 0);
        vector<int> next(k, 0);
        int min_pos, first, second;


        for(auto& cost: costs)
        {
            first = INT_MAX;
            second = INT_MAX;
            for(int i = 0; i < k; i++)
            {
                if(cur[i] < first)
                {
                    min_pos = i; 
                    second = first;
                    first = cur[i];
                }
                else if(cur[i] < second)
                    second = cur[i];
            }

            for(int i = 0; i < k; i++)
            {
                if(i == min_pos)
                    cur[i] = second + cost[i];
                else    
                    cur[i] = first + cost[i];
            }
        }

        first = INT_MAX;
        for(int i = 0; i < k; i++)
            first = min(cur[i], first);
        return first;
            
        
    }
};