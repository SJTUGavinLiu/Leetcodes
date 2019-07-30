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
    string longestPalindrome(string s){
        if(s.size() == 0)   return "";
        int n = s.size();
        int left,right;
        int Max = 0;
        int cur,beg;

        for(int i = 0; i < n; i++)
        {
            //单数
            left = i - 1;
            right = i + 1;
            while(left >= 0 && right < n)
            {
                if(s[left] != s[right]) break;
                left--;
                right++;
            }
            cur = right - left -1;
            if(cur > Max)
            {
                Max = cur;
                beg = left + 1;
            }
            
            left = i;
            right = i + 1;
            while(left >= 0 && right < n)
            {
                if(s[left] != s[right]) break;
                left--;
                right++;
            }
            cur = right - left - 1;
            if(cur > Max)
            {
                Max = cur;
                beg = left + 1;
            }
            if(Max/2 >= (n - i - 1))    break;
        }
        return s.substr(beg,Max);
    }

};