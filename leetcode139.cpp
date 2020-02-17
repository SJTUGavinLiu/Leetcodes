class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len+1, 0);
        dp[0] = 1;
        for(int i = 0; i < len; i++)
        {
            for(auto& word: wordDict)
            {
                int wordLen = word.size();
                if(word.back() == s[i] && i - wordLen + 1 >= 0 && dp[i-wordLen+1] && s.substr(i-wordLen+1,wordLen) == word)
                {
                    dp[i+1] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};