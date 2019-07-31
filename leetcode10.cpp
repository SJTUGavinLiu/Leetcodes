#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1,0));
        // dp[m][n]表示 s:[0,m) 是否与 p[0,n)匹配
        dp[0][0] = 1;
        for(int i = 0; i < m + 1; i++)
        {
            for(int j = 1; j < n + 1; j++)
            {
                if(p[j-1] == '*')
                {
                    dp[i][j] = (j > 1 && dp[i][j-2]) || (i > 0 && j > 1 && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                }   
                else if(p[j-1] == '.')
                {
                    dp[i][j] = i > 0 && dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && s[i-1] == p[j-1];
                }
                
            }
        }
        return dp[m][n];
    }
};