class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int tmp = 0;
        for(auto c: s)
        {
            if(c == ' ')    
            {
                tmp = cnt == 0 ? tmp: cnt;
                cnt = 0;
            }
            else    cnt++;
        }
        return cnt == 0 ? tmp : cnt;
    }
};

