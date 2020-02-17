class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())    return 0;
        vector<int> dp(triangle.size(), 0);
        dp[0] = triangle[0][0];

        int pre,tmp;
        for(int i = 1; i < triangle.size(); i++)
        {
            pre = dp[0];
            dp[0] = pre + triangle[i][0];
            for(int j = 1; j < i; j++)
            {
                tmp = dp[j];
                dp[j] = triangle[i][j] + min(pre, dp[j]);
                pre = tmp;
            }
            dp[i] = pre + triangle[i][i];
        }

        int Min = dp[0];
        for(int i = 1; i < triangle.size(); i++)
        {
            Min = min(Min, dp[i]);
        }
        return Min;
    }
};
/*
class Solution {
int Min;
public:
    void Search(vector<vector<int>>& triangle, int layer, int pos, int sum)
    {
        if(layer == triangle.size())
        {
            Min = min(Min, sum);
        }
        else
        {
            Search(triangle, layer+1,pos,sum+triangle[layer][pos]);
            Search(triangle, layer+1,pos+1,sum+triangle[layer][pos]);
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        Min = INT_MAX;   
        if(triangle.empty())    return 0;
        Search(triangle, 0, 0, 0);
        return Min;
    }
};
*/