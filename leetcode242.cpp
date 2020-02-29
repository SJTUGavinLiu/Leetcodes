class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())    return false;
        vector<int> count(26,0);
        for(auto& c: s)
            count[c-'a']++;
        for(auto& c: t)
        {
            count[c-'a']--;
            if(count[c-'a'] < 0)    return false;
        }
        return true;
    }
};