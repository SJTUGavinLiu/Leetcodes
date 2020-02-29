class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        //vector<vector<int>> dp(costs.size()+1, vector<int>(3,INT_MAX));
        int first = 0, second = 0, third = 0;
        int tmp_first, tmp_second, tmp_third;
        for(auto& cost: costs)
        {
            tmp_first = min(second, third) + cost[0];
            tmp_second = min(first, third) + cost[1];
            tmp_third = min(first, second) + cost[2];
            first = tmp_first;
            second = tmp_second;
            third = tmp_third;
        }

        return min(min(first, second), third);


        
    }
};



class Solution {
    int res;
public:
    void helper(vector<vector<int>>& costs, int ban, int pos, int sum)
    {
        if(sum >= res)  return;
        if(pos == costs.size()) 
        {
            res = min(res, sum);
            return;
        }
        for(int i = 0; i <= 2; i++)
        {
            if(ban == i)    continue;
            helper(costs, i, pos+1, sum+costs[pos][i]);
        }
    }
    int minCost(vector<vector<int>>& costs) {
        res = INT_MAX;
        helper(costs, -1, 0, 0);
        return res;
    }
};