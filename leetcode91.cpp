class Solution {
public:
    
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0')
            return 0;


        int len = s.size();
        vector<int> dp(len+1,0);
        if(s[0] == '0')
            return 0;
        dp[len] = 1;
        dp[len-1] = s[len-1] != '0';

        
        for(int i = len-2; i >= 0; i--)
        {
            if(s[i] == '0')
            {
                dp[i] = 0;
            }
            else
            {
                if(s[i] <= '1' || (s[i] == '2' && s[i+1] <= '6'))
                {
                    dp[i] = dp[i+1] + dp[i+2];
                }
                else
                {
                    dp[i] = dp[i+1];
                }
                
            }

        }
        return dp[0];


    }
};





/*
class Solution {
public:
    int helper(string s, int pos)
    {
        if(s.size() == pos)
        {
            return 1;
        }
        else
        {
            if(s[pos] == '0')   return 0;
            int sum = helper(s, pos+1);
            if(s.size() > (pos+1))          
            {
                if(s[pos] <= '1' || (s[pos] == '2' && s[pos+1] <= '6'))
                    return sum + helper(s, pos+2);
            }
            return sum;
        }
    }
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        return helper(s, 0);
    }
};
*/