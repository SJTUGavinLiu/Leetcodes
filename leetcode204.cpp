class Solution {
public:
    int countPrimes(int n) {
        if(n < 3)
            return 0;
        
        vector<bool> flag(n, true);
        int count = 0;
        for(int i = 2*2; i < n; i+=2)
        {
            count++;
            flag[i] = false;
        }
        
        for(int i = 3; i <= sqrt(n) + 1; i+=2)
        {
            if(flag[i])
            {
                for(int j = i * 2; j < n; j += i)
                {
                    if(flag[j]) 
                    {
                        flag[j] = 0;
                        count++;
                    }
                }
            }
        }
        return n - count - 2;
    }
};