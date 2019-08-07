#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for(auto &c : s)
        {
            if(c == '(' || c == '[' || c == '{')
            {
                stack.push_back(c);
            }
            else if(c == ')' || c == ']' || c =='}')
            {
                if(stack.empty())   return false;
                else
                {
                    if((stack.back()=='(' && c==')') || (stack.back()=='{' && c=='}') || (stack.back()=='[' && c==']'))
                        stack.pop_back();
                    else
                        return false;
                }
            }
        }
        if(stack.empty())   return true;
        else    return false;
    }
};