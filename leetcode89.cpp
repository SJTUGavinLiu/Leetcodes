class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0)  return {0};
        else if(n == 1)  return {0,1};
        else if(n == 2) return {0, 1, 3, 2};
        int cnt = 3;
        vector<int> tmp = {0, 1, 3, 2};
        while(cnt <= n)
        {
            int len = tmp.size();
            for(int i = 0; i < len; i++)
            {
                tmp[i] *= 2;
            }
            for(int i = len-1; i >=0 ; i--)
            {
                tmp.push_back(tmp[i] + 1);
            }
            cnt++;
        }
        return tmp;
        
        
        
        

    }
};