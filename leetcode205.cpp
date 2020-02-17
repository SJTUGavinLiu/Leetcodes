class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())    return false;
        vector<int> dict(256, -1);
        vector<bool> place(256, false); 
        for(int i = 0; i < s.size(); i++)
        {
            if(dict[s[i]] == -1)
            {
                if(place[t[i]]) return false;
                place[t[i]] = 1;
                dict[s[i]] = t[i];
            }
            else
            {
                if(dict[s[i]] != t[i])
                    return false;
            }
        }
        return true;
         
    }
};