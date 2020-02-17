/* 
    Solution 1 DP
    dp[i] -> s[0:i-1]'s minCut
*/

class Solution {
public:
    bool isPalin(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;   
        }
        return true;
    }
    int minCut(string s) {
        if(s.empty())   return 0;
        int len = s.size();
        vector<int> dp(len+1,INT_MAX);
        dp[0] = -1;
        for(int j = 0; j < len; j++)
        {
            for(int i = j; i >= 0; i--)
            {
                if(isPalin(s.substr(i,j-i+1)))
                    dp[j+1] = min(dp[j+1],1+dp[i]);
            }
        }
        return dp[len];
    }
};
/*
    Solution 2
    中心扩散

*/
class Solution {
private:
    int len;
public:
    void SearchPalin(string&s, vector<vector<bool>>& isPalin, int i, int j)
    {
        while(i >= 0 && j < len && s[i] == s[j])
        {
            isPalin[i][j] = 1;
            i--;
            j++;
        }
    }
    int minCut(string s) {
        if(s.empty())   return 0;
        len = s.size();
        vector<vector<bool>> isPalin(len, vector<bool>(len,0));
        for(int i = 0; i < len; i++)
        {
            SearchPalin(s, isPalin, i, i);
            SearchPalin(s, isPalin, i, i+1);
        }
        vector<int> dp(len+1,INT_MAX);
        dp[0] = -1;
        for(int j = 0; j < len; j++)
        {
            for(int i = j; i >= 0; i--)
            {
                if(isPalin[i][j])
                    dp[j+1] = min(dp[j+1],1+dp[i]);
            }
        }
        return dp[len];


    }
};
/*
    Solution 3
    中心扩散 空间优化
*/

class Solution {
private:
    int len;
public:
    void helper(string s, int left, int right, vector<int>& dp)
    {
        while(left >= 0 && right < len && s[left] == s[right])
        {
            if(left == 0)
                dp[right] = 0;
            else
                dp[right] = min (dp[right], dp[left-1] + 1); 
            left--;
            right++;
        }
    }
    int minCut(string s) {
        if(s.empty())   return 0;
        len = s.size();
        vector<int> dp(len,INT_MAX);

        for(int i =0 ; i < len; i++)
        {
            helper(s,i,i,dp);
            helper(s,i,i+1,dp);
        }
        return dp.back();
    }
};

