#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())    return "";
        string prefix = strs[0];
        int len = 0;
        for(auto &item : strs)
        {
            len = 0;
            for(int i = 0; i < prefix.size(); i++)
            {
                if(i >= item.size() || item[i] != prefix[i])    break;
                len++;
            }
            prefix = prefix.substr(0,len);
        }
        return prefix;
    }
};