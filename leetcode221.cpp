class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        
        int height = matrix.size();
        int width = matrix[0].size();
        int Max = 0;
        vector<vector<int>> dp(height, vector<int>(width, 0));
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                if(matrix[i][j] == '0')  continue;

                if(i > 0 && j > 0)
                {
                    int edge = min(dp[i-1][j-1], min(i, j));
                    dp[i][j] = 1;
                    for(int k = 1; k <= edge; k++)
                    {
                        if(matrix[i-k][j] != '1'  || matrix[i][j-k] != '1')
                            break;
                        dp[i][j]++;
                    }   

                }
                else
                {
                    dp[i][j] = 1;
                }
                if(dp[i][j] > Max)
                    Max = dp[i][j];
            }

            
        }
        return Max*Max;
    }
};

