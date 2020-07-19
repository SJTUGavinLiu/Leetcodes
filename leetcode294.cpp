class Solution {
private:
    string s;
    bool helper()
    {
        for(int i = 0; i < s.size()-1; i++)
        {
            if(s[i] == '+' && s[i+1] == '+')
            {
                s[i] = s[i+1] = '-';
                if(!helper())   
                {
                    s[i] = s[i+1] = '+';
                    return true;  
                }
                s[i] = s[i+1] = '+';
            }
        }
        return false;
    }
public:
    bool canWin(string s_) {
        if(s_.size() < 2)   return false;
        s = s_;
        return helper();
    }
};