#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
using namespace std::tr1;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0) return res;
        unordered_map<char,string> map;
        map['2']="abc";
        map['3']="def";
        map['4']="ghi";
        map['5']="jkl";
        map['6']="mno";
        map['7']="pqrs";
        map['8']="tuv";
        map['9']="wxyz";
        for(int i=0;i<map[digits[0]].size();i++)
        {
            res.push_back(map[digits[0]].substr(i,1));
        }
        letterCombination(digits.substr(1,digits.size()-1),res,map);
        return res;
        
    }
    void letterCombination(string digits, vector<string> &res,unordered_map<char,string> &map)
    {
        if(digits.size()==0) return;
        char tar=digits[0];
        int length=res.size();
        for(int i =0;i<map[tar].size();i++)
        {
            if(i==(map[tar].size()-1))
            {
                for(int j=0;j<length;j++)
                {
                    res[j]+=map[tar][i];                    
                }
            }
            
            else
            {
                for(int j=0;j<length;j++)
                {
                    res.push_back(res[j]+map[tar][i]);
                }
                
            }
        }
        letterCombination(digits.substr(1,digits.size()-1),res,map);
    }
};