class Solution {
private:
    int len;
    vector<string> tmp;
    vector<vector<string>> res;
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
    void backtrack(int beg, string& s, vector<vector<bool>>& dp)
    {
        if(beg == len)  
        {
            res.push_back(tmp);
            return;
        }
        int wordLen;
        for(int i = beg; i < len; i++)
        {
            if(dp[beg][i])
            {
                tmp.push_back(s.substr(beg,i-beg+1));
                backtrack(i+1,s, dp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, 0));
        for(int i = 0; i < len; i++)
        {
            for(int j = i; j < len; j++)
            {
                if(isPalin(s.substr(i,j-i+1)))
                    dp[i][j] = 1;
            }
        }
        backtrack(0,s,dp);
        return res;
    }
};class Solution {
private:
    int len;
    vector<string> tmp;
    vector<vector<string>> res;
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
    void backtrack(int beg, string& s, vector<vector<bool>>& dp)
    {
        if(beg == len)  
        {
            res.push_back(tmp);
            return;
        }
        int wordLen;
        for(int i = beg; i < len; i++)
        {
            if(dp[beg][i])
            {
                tmp.push_back(s.substr(beg,i-beg+1));
                backtrack(i+1,s, dp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, 0));
        for(int i = 0; i < len; i++)
        {
            for(int j = i; j < len; j++)
            {
                if(isPalin(s.substr(i,j-i+1)))
                    dp[i][j] = 1;
            }
        }
        backtrack(0,s,dp);
        return res;
    }
};