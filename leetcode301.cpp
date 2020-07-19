class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> qu1, qu2;
        qu1.insert(s);
        int len = s.size();
        bool flag = 1;
        //int cnt = 0;
        while(flag && len)
        {
            string tmp(len-1,'0');
            for(auto& cur: qu1)
            {
                //cnt++;
                int count1 = 0;
                int count2 = 0;
                for(int i = 0; i < len; i++)
                {
                    if(cur[i] == '(')   count1++;
                    else if(cur[i] == ')')   count2++;
                    else continue;
                    if(i == 0 || cur[i] != cur[i-1])
                    {
                        for(int j = 0; j < i; j++)   tmp[j] = cur[j];
                        for(int j = i+1; j < len; j++)  tmp[j-1] = cur[j];
                        qu2.insert(tmp);
                        //cout << i << '\t';
                    }
                    if(count2 > count1)
                        break;
                }
                if(count1 == count2)    
                {
                    res.push_back(cur);
                    flag = 0;
                }
            }
            len--;     
            swap(qu1, qu2);
            qu2.clear();
        }
        //cout << cnt;
        if(res.empty()) res.push_back("");
        return res;
    }
};