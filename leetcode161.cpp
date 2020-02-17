class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size() == t.size())
        {
            int cnt = 0;
            for(int i = 0; i < s.size(); i++)
            {
                if(s[i] != t[i])    cnt++;
                if(cnt >= 2)    break;
            }
            return cnt == 1;
        }
        else if((s.size() + 1) == t.size())
        {
            int i = 0;
            int j = 0;
            while(i < s.size() && j < t.size())
            {
                if(s[i] != t[j])
                {
                    j++;
                    break;
                }
                i++;
                j++;
            }
            while(i < s.size() && j < t.size())
            {
                if(s[i] != t[j])    return false;
                i++;
                j++;
            }
            return true;
        }
        else if(s.size() == (t.size() + 1))
        {
            int i = 0;
            int j = 0;
            while(i < s.size() && j < t.size())
            {
                if(s[i] != t[j])
                {
                    i++;
                    break;
                }
                i++;
                j++;
            }
            while(i < s.size() && j < t.size())
            {
                if(s[i] != t[j])    return false;
                i++;
                j++;
            }
            return true;
        }
        return false;
    }
};