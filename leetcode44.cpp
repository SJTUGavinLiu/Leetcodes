#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())   return s.empty();
        if(s.empty())
        {
            for(char c: p)
            {
                if(c != '*')
                    return false;
            }
            return true;
        }
        int a = s.size();
        int b = p.size();
        bool **dp = new bool*[a+1];
        bool *col = new bool[b+1]; 
        /* col[j] denotes whether there is a i so that b[0:j] can be matched with a[0:i] now*/
        for(int i = 0; i <= b; i++)
        {
            col[i] = false;
        }
        for(int i = 0; i <= a; i++)
        {
            dp[i] = new bool[b+1];
            for(int j = 0; j <= b; j++)
            {
                dp[i][j] = false;
            }
        }

        dp[0][0] = true;

        //if(dp[a][b]) return false;
        

        if(p[0] == '*')   
        {
            dp[0][1] = true;
            col[0] = col[1] = 1; 
            /*col[0] can only function when j == 1 */
            for(int i = 1; i < b; i++)
            {
                if(p[i] == '*')
                    dp[0][i+1] = true;
                else
                    break;

            }
        }
        /* make sure when p[0] equals to * */


        

        for(int i = 1; i <= a; i++)
        {
            for(int j = 1; j <= b; j++)
            {
                if(p[j-1] == '*')
                {
                    
                    if(col[j-1])
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                    
                }
                else if(p[j-1] == '?')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    if(p[j-1] == s[i-1])
                        dp[i][j] = dp[i-1][j-1]; 
                }
                
                if(dp[i][j])    col[j] = true;
            }
        }
        
        return dp[a][b];


    }
};

/* O(n) Space Complexity */
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())   return s.empty();
        if(s.empty())
        {
            for(char c: p)
            {
                if(c != '*')
                    return false;
            }
            return true;
        }
        int a = s.size();
        int b = p.size();
        bool **dp = new bool*[2];
        bool *col = new bool[b+1]; 
        /* col[j] denotes whether there is a i so that b[0:j] can be matched with a[0:i] now*/
        for(int i = 0; i <= b; i++)
        {
            col[i] = false;
        }
        for(int i = 0; i <= 1; i++)
        {
            dp[i] = new bool[b+1];
            for(int j = 0; j <= b; j++)
            {
                dp[i][j] = false;
            }
        }

        dp[0][0] = true;

        //if(dp[a][b]) return false;
        

        if(p[0] == '*')   
        {
            dp[0][1] = true;
            col[0] = col[1] = 1; 
            /*col[0] can only function when j == 1 */
            for(int i = 1; i <= b; i++)
            {
                if(p[i] == '*')
                {
                    dp[0][i+1] = true;
                    col[i+1] = true;
                }    
                else
                    break;

            }
        }
        /* make sure when p[0] equals to * */


        

        for(int i = 1; i <= a; i++)
        {
            for(int j = 1; j <= b; j++)
            {
                if(p[j-1] == '*')
                {
                    
                    if(col[j-1])
                        dp[1][j] = true;
                    else
                        dp[1][j] = false;
                    
                }
                else if(p[j-1] == '?')
                {
                    dp[1][j] = dp[0][j-1];
                }
                else
                {
                    if(p[j-1] == s[i-1])
                        dp[1][j] = dp[0][j-1]; 
                    else
                        dp[1][j] = false;
                }
                
                dp[0][j-1] = dp[1][j-1];
                if(dp[1][j])    col[j] = true;
            }
            dp[0][b] = dp[1][b];
        }
        
        return dp[0][b];


    }
};

/* non-dp version */


class Solution {
public:
    bool isMatch(string s, string p) {
        char *sptr = &s[0];
        char *ptr = &p[0];
        char *pstar = NULL;
        char *sstar = NULL;

        while(*sptr)
        {
            if(*sptr == *ptr || *ptr == '?')
            {
                sptr++;ptr++;
            }
            else if( *ptr == '*')
            {
                pstar = ptr++;
                sstar = sptr;
            }
            else if(pstar)
            {
                ptr = pstar + 1;
                sptr = ++sstar;
            }
            else
            {
                return false;
            }
            
        }
        while(*ptr == '*')  ptr++;
        return !*ptr;

        
    }
};