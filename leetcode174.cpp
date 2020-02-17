class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int height = dungeon.size();
        int width = dungeon[0].size();
        vector<vector<int>> dp(height, vector<int>(width,0));
        dp[height-1][width-1] = max(1, 1-dungeon[height-1][width-1]);

        for(int i = height-2; i >= 0; i--)
            dp[i][width-1] = max(1, dp[i+1][width-1] - dungeon[i][width-1]);
        for(int j = width - 2; j >= 0; j--)
            dp[height-1][j] = max(1, dp[height-1][j+1] - dungeon[height-1][j]);

        for(int i = height -2; i >= 0; i--)
        {
            for(int j = width - 2; j >= 0; j--)
            {
                dp[i][j] = max(1, min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};


/*
    空间压缩
*/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int height = dungeon.size();
        int width = dungeon[0].size();
        vector<int> dp(width, 0);
        dp[width-1] = max(1, 1-dungeon[height-1][width-1]);

        for(int j = width - 2; j >= 0; j--)
            dp[j] = max(1, dp[j+1] - dungeon[height-1][j]);

        for(int i = height -2; i >= 0; i--)
        {
            dp[width - 1] = max(1, dp[width-1] - dungeon[i][width-1]); 
            for(int j = width - 2; j >= 0; j--)
            {
                dp[j] = max(1, min(dp[j+1], dp[j]) - dungeon[i][j]);
            }
        }
        return dp[0];
    }
};




