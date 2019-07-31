#include<string>
#include<unordered_map>
using namespace std;
using namespace std::tr1;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> map;
        map['O']=0;
        map['I']=1;
        map['V']=5;
        map['X']=10;
        map['L']=50;
        map['C']=100;
        map['D']=500;
        map['M']=1000;
        char cur=40,pre;
        int num=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            pre=cur;
            cur = s[i];
            if(map[cur]<map[pre])
            {
                num-=map[cur];
            }
            else
            {
                num+=map[cur];
            }
        
        }
        return num;    
    }
};