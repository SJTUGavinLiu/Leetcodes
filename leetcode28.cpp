
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        if(haystack.size()==0 || (needle.size() > haystack.size()))  return -1;
        int start;
        for(int k = 0;k<(haystack.size()-needle.size()+1);k++)
        {
            if(haystack[k]==needle[0])
            {
                int i=k;
                int j=0;
                start=i;
                while(i<haystack.size())
                {
                    
                    if(haystack[i]!=needle[j])
                        break;
                    else
                    {
                        if(j==(needle.size()-1))    return start;
                        i++;
                        j++;
                    }
                }
                
            }
            
            
        }
        return -1;
    }
};