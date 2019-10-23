#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())   return 0;
        int size = s.size();
        int Max = 0;
        vector<int> dp(size,0);
        for(int i = 1; i < size; i++)
        {
            if(s[i] == '(')   continue;
            else if(s[i-dp[i-1]-1] == '(')
                dp[i] = dp[i-1] + 2 + (i-dp[i-1]-2 >0 ? dp[i-dp[i-1]-2]:0);
            Max = max(Max,dp[i]);
        }
        return Max;
    }
};