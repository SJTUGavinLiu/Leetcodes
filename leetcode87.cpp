class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)
            return true;
        if(s1.size() != s2.size())
            return false;
        //unordered_map<char> dict;

        int len = s1.size();
        vector<vector<vector<int>>> dp(len,vector<vector<int>>(len,vector<int>(len+1,0)));
        //dp[i][j][len]: s1.substr(i,len) can be matched by s2.substr(j,len)

        for(int i = 0; i < len;i++)
        {
            for(int j = 0; j < len; j++)
            {
                dp[i][j][1] = s1[i] == s2[j];
                dp[i][j][0] = 1;
            }
        }

        for(int l = 2; l <= len; l++)
        {
            for(int i = 0; i < (len - l + 1); i++)
            {
                for(int j = 0; j < (len - l + 1); j++)
                {
                    for(int  k = 1; k < l; k++)
                    {
                        if(dp[i][j][k] && dp[i+k][j+k][l-k])
                        {
                            dp[i][j][l] = 1;
                            break;
                        }
                        else if(dp[i][j+l-k][k] && dp[i+k][j][l-k])
                        {
                            dp[i][j][l] = 1;
                            break;
                        }
                    }
                }
            }
            
        }

        return dp[0][0][len];



    }
};