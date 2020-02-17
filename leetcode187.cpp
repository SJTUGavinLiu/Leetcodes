class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10)   return {};
        unordered_map<string, bool> dict;
        vector<string> res;
        for(int i =0; i <= s.size() - 10; i++)
        {
            string tmp = s.substr(i,10);
            if(!dict.count(tmp))
            {
                dict[tmp] = 1;
            }
            else
            {
                if(dict[tmp])
                {
                    res.push_back(tmp);
                    dict[tmp] = 0;
                }
            }

        }
        return res;
    }
};

class Solution {
public:
    int encode(char& c)
    {
        switch(c)
        {
            case: 'A': return 0;
            case: 'T': return 1;
            case: 'G': return 2;
            case: 'C': return 3;
        }
    }
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10)   return {};
        unordered_map<int, bool> dict;
        vector<string> res;
        int tmp;
        for(int i = 0; i < 10; i++)
        {
            tmp = tmp | encode(s[i]);
            tmp = tmp << 2;
        }
        dict[tmp] = 1;

        for(int i = 10; i < s.size(); i++)
        {
            tmp = tmp << 2;
            tmp = tmp | encode(s[i]);
            if(dict.count(tmp))
            {
                if(dict[tmp])
                {
                    res.push(s.substr(i-9,10));
                    dict[tmp] = 0;
                }
            }
            else
            {
                dict[tmp] = 1;
            }
        }
        return res;
    }
};





class Solution {
public:
    int encode(char& c)
    {
        switch(c)
        {
            case 'A': return 0;
            case 'T': return 1;
            case 'G': return 2;
            case 'C': return 3;
        }
        return -1;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10)   return {};
        unordered_map<int, bool> dict;
        vector<string> res;
        int tmp = 0;
        for(int i = 0; i < 10; i++)
        {
            tmp = tmp << 2;
            tmp = tmp | encode(s[i]);
        }
        dict[tmp] = 1;
        int mask = (1 << 20) - 1;
        

        for(int i = 10; i < s.size(); i++)
        {
            tmp = tmp << 2;
            tmp = tmp | encode(s[i]);
            tmp = tmp & mask;
            if(dict.count(tmp))
            {
                if(dict[tmp])
                {
                    res.push_back(s.substr(i-9,10));
                    dict[tmp] = 0;
                }
            }
            else
            {
                dict[tmp] = 1;
            }
        }
        return res;
    }
};