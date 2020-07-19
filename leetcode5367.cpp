class Solution {
public:
    string longestPrefix(string s) {
        if(s.empty())   return "";
        vector<int> next(s.size()+1, 0);
        next[0] = -1;
        next[1] = 0;
        for(int i = 2; i <= s.size(); i++)
        {
            int tmp = i-1;
            while(tmp > 0 && s[next[tmp]] != s[i-1])    
                tmp = next[tmp];
        
            next[i] = next[tmp] + 1;
        }
        return s.substr(0,next[s.size()]);
    }
};