class Solution {
public:
    int countDigitOne(int n) {
        if(n < 1)   return 0;
        int cnt = 0;
        for(long i = 1; i <= n; i*=10)
        {
            int over = n/i;
            int reamin = n%i;
            cnt += (over/10) * i;
            if(over%10 == 1)    cnt += (reamin+1);
            else if(over%10 > 1)    cnt += i;
        }
        return cnt;
    }
};