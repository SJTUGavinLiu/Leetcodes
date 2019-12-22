class Solution {
public:
    string minWindow(string s, string t) {
        int beg = 0;
        int end = 0;
        int res_beg = 0;
        int res_length = INT_MAX;
        int sum = t.size();
        unordered_map<char,int> dict;
        for(char c: t)
        {
            if(dict.find(c) == dict.end())
                dict[c] = 1;
            else
                dict[c]++;
        }

        while(end < s.size())
        {
            while(end < s.size())
            {
                if(dict.find(s[end]) != dict.end())
                {
                    //cout<<end<<" ";
                    //cout<<s[end];
                    if(dict[s[end]] <= 0)
                    {
                        dict[s[end]]--;
                    }
                    else
                    {
                        dict[s[end]]--;
                        sum--;
                    }
                    cout << sum <<endl;
                    if(sum == 0)
                        break;
                    
                }
                end++;
            }
            if(end == s.size())
                break;
            while(beg < end)
            { 
                if(dict.find(s[beg]) != dict.end())
                {
                    dict[s[beg]]++;
                    if(dict[s[beg]] == 1)
                    {
                        sum = 1;
                        break;
                    }
                    
                }
                beg++;
            }
            //cout<<endl<<(end - beg + 1)<<endl;
            if((end - beg + 1) < res_length)
            {
                res_beg = beg;
                res_length = end - beg + 1;
                
            }
            beg++;
            end++;
        }
        if(beg == 0 && end == s.size())
            return "";
        return s.substr(res_beg, res_length);

    }
};