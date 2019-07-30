#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>



using namespace std;
using namespace std::tr1;


class Solution{
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.size() == 0)   return 0;
        int res = 1;
        unordered_map<char,int> dict;
        int i =0;
        for(int j = 0; j < s.size(); j++)
        {
            if(dict.find(s[j])!=dict.end()) i = max(i,dict[s[j]]);
            res = max(res, j - i + 1);
            dict[s[j]] = j + 1;  
        }
        
        return res;
    }

};
/*
//针对字母串情况
//
class Solution{
public:
    int lengthOfLongestSubstring(string s)
    {
        if(s.size() == 0)   return 0;
        int res = 1;
        vector<int> marks(26,0);
        int i = 0, j = 0;
        while(j < s.size())
        {
            if(marks[s[j]-'a'])
            {
                res = res > (j - i) ? res : (j - i);
                while(s[j] != s[i])
                {
                    marks[s[i] - 'a'] = 0;
                    i++;
                }
                i++;
            }
            marks[s[j] - 'a'] = 1;
            j++;
        } 
        res = res > (s.size() - i) ? res : (s.size() - i);
        return res;
    }
};
*/