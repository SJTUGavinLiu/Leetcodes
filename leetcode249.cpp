class Solution {
private:
    bool isSame(string& a, string& b)
    {
        if(a.size() != b.size())    return false;

    }
    
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> dict;
        vector<string> ind;
        vector<vector<string>> res;
        bool flag = 1;
        for(auto& s: strings)
        {
            if(s == "")
            {
                if(flag)
                {
                    res.push_back({});
                    flag = 0;
                }
                res[0].push_back("");
                continue;
            }
            string tmp(s.size()-1,'0');
            
            for(int i = 0; i < s.size() - 1; i++)
            {
                int dis = s[i+1] - s[i];
                if(dis < 0) dis += 26;
                tmp[i] = dis + 'a';
            }
            if(!dict.count(tmp))
                ind.push_back(tmp);
            dict[tmp].push_back(s);
        }

        for(auto& i: ind)
        {
            res.push_back(dict[i]);
        }
        return res;
    }
};