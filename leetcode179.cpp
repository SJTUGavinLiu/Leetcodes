class Solution {
public:
    static bool cmp(string s1, string s2)
    {
        string str1 = s1+s2;
        string str2 = s2+s1;
        return str1>str2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> tmp;
        for(int obj: nums)
            tmp.push_back(to_string(obj));
        
        sort(tmp.begin(),tmp.end(),cmp);
        string res = "";
        for(auto &s: tmp)
            res = res + s;
        
        if(res[0] == '0')   return "0";
        return res;
    }
};