class Solution {
public:
    string reverseWords(string s) {
        vector<string> tmp;
        int len = s.size();
        int i = 0;
        while(i < len)
        {
            while(i < len && s[i] == ' ')
                i++;
            if(i == len)    break;

            int j = i+1;
            while(j < len && s[j] != ' ')
                j++;
            tmp.push_back(s.substr(i,j-i));
            i = j;
        }
        if(tmp.empty()) return "";
        //cout << tmp.size();
        string res = tmp.back();
        for(int i = tmp.size() - 2; i >= 0; i--)
        {
            res = res + " " + tmp[i];
        }
        return res;
    }
};