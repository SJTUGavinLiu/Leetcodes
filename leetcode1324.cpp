class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> res;
        int flag = 1;
        int i = 0, j = -1, k = 0;

        while(k < s.size())
        {
            if(s[k] == ' ')
            {
                flag = 1;
                k++;
                continue;
            }

            if(flag)    //begin of new word
            {
                i = 0;
                j++;     
                flag = 0;           
            }
            while(k < s.size() && s[k] != ' ')
            {
                if(i >= res.size())
                    res.push_back(string(j, ' '));
                if(res[i].size() < j)
                    res[i] = res[i] + string(j-res[i].size(), ' ');
                
                res[i] = res[i] + s[k];
                i++;
                k++;
            }
            if(k == s.size())
                break;
        }
        return res;
    }
};