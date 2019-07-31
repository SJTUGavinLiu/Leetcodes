#include<string>
using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        string res="";
        string str[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int data[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        for(int i=0;i<13;i++)
        {
            if(i==0 || i==4 || i==8 || i ==12)
            {
                while(num>=data[i])
                {
                    num-=data[i];
                    res+=str[i];
                }
            }
            else
            {
                if(num>=data[i])
                {
                    num-=data[i];
                    res+=str[i];
                }
            }
        }
        
        
        return res;
        
    }
};