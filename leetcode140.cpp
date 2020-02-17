class Solution {
private:
    int len;
    vector<string> tmp;
    vector<string> res;
public:
    bool helper(string s, vector<string>& wordDict) {
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

    void backtrack(int i, string& s, vector<string>& wordDict)
    {
        if(len == i)
        {
            string s = tmp[0];
            for(int i = 1; i < tmp.size(); i++)
            {
                s = s + " " + tmp[i];
            }
            res.push_back(s);
            return;
        }    
            

        for(auto& word: wordDict)
        {
            int wordLen = word.size();
            if(wordLen + i > len || word[0] != s[i])   continue;
            if(s.substr(i, wordLen) == word)
            {
                tmp.push_back(word);
                backtrack(i+wordLen, s, wordDict);
                tmp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        len = s.size();
        if(helper(s,wordDict))
            backtrack(0, s, wordDict);
        return res;
    }
};