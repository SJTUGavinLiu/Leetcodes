#include<iostream>
#include<vector>
#include<string>
using namespace std;


static const auto __ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution{
public:
    string convert(string str, int numRows)
    {
        if(numRows == 1 || str.size() == 0)    return str;
        int group = 2 * numRows - 2;
        int half = numRows - 1;
        string s = "";
        int i = 0;
        while(i < str.size())
        {
            s = s + str[i];
            i += group;
        }
        for(int j = 1; j < half; j++)
        {
            i = 0;
            while(i < str.size())
            {
                if(i + j >= str.size())    break;
                s = s + str[i + j];
                if(i + group - j >= str.size())    break;
                s = s + str[i + group -j];
                i += group;
            }
        }
        i = half;
        while(i < str.size())
        {
            s = s + str[i];
            i += group;
        }
        return s;
    }
};