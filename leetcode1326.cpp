class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        if(n == 0)  return 0;
        vector<int> dp(n+2, 0);
        dp[0] = 0;
        dp[1] = ranges[0];
        if(dp[1] >= n)  return 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                //cout << dp[j] << '\t';
                if(dp[j] >= i - ranges[i])
                {
                    dp[j+1] = max(dp[j+1], i + ranges[i]);
                    if(dp[j+1] >= n)
                        return j+1;
                }
            }
            cout << endl;
        }
        return -1;
    }
};