class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.empty())   return 1;
        if(s.empty())   return 0;
        vector<vector<long>> dp(s.size()+1, vector<long>(t.size()+1,0));

        
        for(int i = 0; i <= s.size(); i++)
        {
            dp[i][0] = 1;
        }
        for(int i = 1; i <= s.size(); i++)
        {

            for(int j = 1; j <= t.size(); j++)
            {
                dp[i][j] = dp[i-1][j] + ((s[i-1] == t[j-1]) ? dp[i-1][j-1] : 0);     
            }
        }
        /*
        for(int i = 0; i <= s.size(); i++)
        {
            for(int j = 0; j <= t.size(); j++)
            {
                cout << dp[i][j] << " ";
            }
            cout<<endl;
        }
        */
        return dp[s.size()][t.size()];
    }
};