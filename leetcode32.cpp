#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())   return 0;
        int size = s.size();
        int Max = 0;
        vector<int> dp(size,0);
        for(int i = 1; i < size; i++)
        {
            if(s[i] == '(')   continue;
            else if(s[i-dp[i-1]-1] == '(')
                dp[i] = dp[i-1] + 2 + (i-dp[i-1]-2 >0 ? dp[i-dp[i-1]-2]:0);
            Max = max(Max,dp[i]);
        }
        return Max;
    }
};





class Solution {
private:
    int len;
    void pos(string& s, int l, int r)
    {
        int beg = l;
        int left = 0;
        int right = 0;
        while(l <= r)
        {
            if(s[l] == '(') left++;
            if(s[l] == ')') right++;
            if(right > left)
            {
                if(left > len)
                    len = left;
                
                beg = l+1;
                left = 0;
                right = 0;
            }
            l++;
        }
        if(right == left && left > len)
            len = left;
        else if(right < left)
        {
            if(right <= len)
                return;
            else
                neg(s, beg, r);   
            
        }
        
    }

    void neg(string& s, int l, int r)
    {
        int beg = r;
        int left = 0;
        int right = 0;
        while(l <= r)
        {
            if(s[r] == '(') left++;
            if(s[r] == ')') right++;
            if(right < left)
            {
                if(right > len)
                    len = right;
                
                beg = r-1;
                left = 0;
                right = 0;
            }
            r--;
        }
        if(right == left && right > len)
            len = right;
        else if(right > left)
        {
            if(left <= len)
                return;
            else
                pos(s, l, beg);   
            
        }
    }
public:
    int longestValidParentheses(string s) {
        if(s.empty())   return 0;
        len = 0;
        pos(s, 0, s.size() - 1);
        return len * 2;

    }
};