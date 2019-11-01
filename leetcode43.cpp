#include<string>
using namespace std;


class Solution {
private:
    string num1;
    string num2;
    int len1;
    int len2;
public:
    int getNum1(int i)
    {
        return num1[len1 - i] - '0';
    }
    int getNum2(int i)
    {
        return num2[len2 - i] - '0';
    }
    string multiply(string n1, string n2) {
        if(n1 == "0" || n2 == "0")  return "0";
        num1 = n1;
        num2 = n2;
        len1 = num1.size() - 1;
        len2 = num2.size() - 1;
        int fir;
        int sec;
        int span = 0;
        int carry = 0;
        int cur = 0;
        string res = "";
        while(span <= len1 + len2)
        {
            cur = carry;
            carry = 0;

            for(int i = len2 > span ? 0 : (span - len2); i <= span; i++)
            {
                if(i > len1)    break;
                int j = span - i;
                fir = getNum1(i);
                sec = getNum2(j);
                int tmp = fir * sec;
                cur += tmp;
            }
            
            carry = cur / 10;
            res = char(cur % 10+ '0') + res;
            span++;
        }
        if(carry > 0)
        {
            res = char(carry + '0') + res;
        }
        return res;
    }
};