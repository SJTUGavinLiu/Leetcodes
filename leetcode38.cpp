#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        string tmp = "";
        int cnt = 0;
        while(--n)
        {
            for(int i = 0; i < cur.size(); i++)
            {
                if(i == 0)  cnt = 1;
                else
                {
                    if(cur[i] != cur[i-1])
                    {
                        tmp = tmp + to_string(cnt) + cur[i-1];
                        cnt = 1;
                    }
                    else
                    {
                        cnt++;
                    }
                    
                }
            }

            tmp = tmp + to_string(cnt) + cur.back();
            cur = tmp;
            tmp = "";
        }
        return cur;
    }
};