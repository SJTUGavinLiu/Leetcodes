#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
using namespace std::tr1;


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size()==0 || s.empty() || s.size()<words.size()*words[0].size())  return {};
        unordered_map<string,int> dict1;
        unordered_map<string,int> dict2;
        vector<int> res;
        int len = words.size() * words[0].size();
        int idx, beg;
        string tmp;
        for(auto& word: words)
        {
            if(dict1.find(word)!=dict1.end()) dict1[word]++;
            else dict1[word] = 1;
        } 
        
        for(int i = 0; i < int(words[0].size()); i++)
        {
            beg = idx = i;
            dict2.clear();
            while(beg + len <= int(s.size()))
            {
                tmp = s.substr(idx,words[0].size());
                if(dict1.find(tmp) == dict1.end())
                {
                    idx += words[0].size();
                    beg = idx;
                    dict2.clear();
                }
                else
                {
                    if(dict2.find(tmp) == dict2.end())  dict2[tmp] = 1;
                    else dict2[tmp]++;
                    if(dict2[tmp] > dict1[tmp])
                    {
                        while(1)
                        {
                            dict2[s.substr(beg,words[0].size())]--;
                            beg += words[0].size();
                            if(dict1[tmp] == dict2[tmp])  break;
                        }

                    }
                    idx += words[0].size();
                    if(idx - beg == len)    res.push_back(beg);
                }
                
                
            }
        }
        return res;
        
    }
};

/*
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size()==0 || s.empty() || s.size()<words.size()*words[0].size())  return {};
        unordered_map<string,int> dict1;
        unordered_map<string,int> dict2;
        vector<int> res;
        for(auto& word: words)
        {
            if(dict1.find(word)!=dict1.end()) dict1[word]++;
            else dict1[word] = 1;
        } 
        int len = words.size() * words[0].size();
        int idx;
        string tmp;
        //无符号整数！！！
        for(int i = 0; i <= int(s.size())-len; i++)
        {
            idx = i; 
            while((idx - i) != len)
            {
                tmp = s.substr(idx,words[0].size());
                if(dict1.find(tmp) == dict1.end()) break;
                else
                {
                    if(dict2.find(tmp) == dict2.end())  dict2[tmp] = 1;
                    else    dict2[tmp]++;
                    if(dict2[tmp]>dict1[tmp])   break;

                    idx += words[0].size();
                }
            }
            dict2.clear();
            if((idx - i) == len)    res.push_back(i);
        }

        return res;
    }
};
*/