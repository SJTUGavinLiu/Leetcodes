class Solution {
private:
    vector<int> cnts; 
    vector<pair<int, int>> dict;
    int cnt;
    int pat_len;
    int str_len;
    bool isExist(int x, int y, string& str)
    {
        if(x > y)   return true;
        for(auto& item: dict)
        {
            if(item.first == -1)
                continue;
            if(y - x == item.second - item.first)
            {
                bool flag = 1;
                for(int i = 0; i <= y - x; i++)
                {
                    if(str[x + i] != str[item.first + i])
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)    return true;
            }
        }
        return false;
    }
public:
    bool helper(string& pattern, int x, string& str, int y)
    {
        if(x == pat_len - 1)
        {
            //cout << x << endl;
            if(dict[pattern[x]-'a'].first == -1)
            {
                //cout << y << '\t' << str_len - 1 <<endl;
                if(isExist(y, str_len - 1, str))    return false;
                return true;
            }
            if(str_len - y != dict[pattern[x] - 'a'].second - dict[pattern[x] - 'a'].first + 1)
                return false;
            for(int i = 0; i < str_len - y; i++)
            {
                if(str[dict[pattern[x] - 'a'].first+i] != str[y+i])
                    return false;
            }
            return true;
        }

        if(dict[pattern[x]-'a'].first == -1)
        {
            int tmp = cnt;
            dict[pattern[x]-'a'].first = y;
            for(int i = y; i < str_len;i++)
            {
                //cout <<pattern[x] << '\t' << y << '\t' << i << '\t' << isExist(y, i, str) << endl;
                if(isExist(y, i, str))  continue;
                cnt = tmp + cnts[pattern[x] - 'a'] * (i - y + 1);
                if(cnt > str_len)    break;
                dict[pattern[x]-'a'].second = i;
                if(helper(pattern, x+1, str, i+1)) return true;
            }
            dict[pattern[x]-'a'].second = -1;
            dict[pattern[x]-'a'].first = -1;
            return false;
        }
        else
        {
            for(int i = dict[pattern[x]-'a'].first; i <= dict[pattern[x]-'a'].second; i++)
            {
                if(str[i] != str[y+i-dict[pattern[x]-'a'].first])
                    return false;
            }
            if(helper(pattern, x+1, str, y + dict[pattern[x]-'a'].second - dict[pattern[x]-'a'].first + 1))
                return true;
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string str) {
        pat_len = pattern.size();
        str_len = str.size();
        if(pat_len == 0 && str_len == 0)    return true;
        if(str_len < pat_len)   return false;    
        if(pat_len == 0)    return false;
        dict = vector<pair<int, int>>(26, {-1,-1});
        cnts = vector<int>(26, 0);
        for(auto&c: pattern)
            cnts[c-'a']++;
        cnt = 0;
        return helper(pattern, 0, str, 0);
        
    }
};