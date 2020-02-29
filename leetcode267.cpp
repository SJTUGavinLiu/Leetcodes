class Solution {
private:
    string tmp;
    int len;
    vector<string> res;
    vector<char> st;
    void helper(int pos, vector<int>& count)
    {

        for(char& c: st)
        {
            if(count[c] == 1 && pos == len / 2 )
            {
                tmp[pos] = c;
                res.push_back(tmp);
            }
            else if(count[c] >= 2 && pos == len / 2)
            {
                tmp[pos] = c;
                tmp[pos+1] = c;
                res.push_back(tmp);
            }
            else if(count[c] >= 2)
            {
                tmp[pos] = c;
                tmp[len-pos] = c;
                count[c] -= 2;
                helper(pos+1, count);
                count[c] += 2;
            }
        }

    }

public:
    vector<string> generatePalindromes(string s) {
        if(s.empty())   return {""};
        vector<int>    count(256, 0);
        int cnt = 0;
        for(auto& c: s)
        {
            if(!count[c])
                st.push_back(c);
            count[c]++;
            if(count[c] % 2 == 0)   cnt--;
            else cnt++;
        }
        if(cnt > 1) return {};

        tmp = s;
        len = s.size() - 1;

        helper(0, count);
        return res;
    }
};