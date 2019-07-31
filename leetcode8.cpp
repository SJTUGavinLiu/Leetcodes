#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

class Solution {
public:
    int myAtoi(string str) {
        int res=0,cur=0;
        bool flag = 1,neg = 0;
        for(char c: str)
        {
            
            if(c==' ' && flag )
                continue;
            else if((c=='-'|| c == '+') && flag)
            {
                if(c=='-')
                    neg=1;
                flag = 0;
            }
            else if(c>=48 && c<=57)
            {
               
                flag =0;
                if(neg)
                {
                    cur=48-c;
                }
                else
                {
                    cur=c-48;
                }
                if (res > INT_MAX/10 || (res == INT_MAX / 10 && cur > 7)) return INT_MAX;
                if (res < INT_MIN/10 || (res == INT_MIN / 10 && cur < -8)) return INT_MIN; 
                res=res*10+cur;
            }
            else
                break;
            
        }
        return res;
    }
};