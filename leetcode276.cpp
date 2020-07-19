class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0)  return 0;

        int sum1 = k;
        int sum2 = 0;
        int tmp1, tmp2;
        for(int i = 1; i < n; i++)
        {
            tmp1 = (k-1) * (sum1 + sum2);
            tmp2 = sum1;

            sum1 = tmp1;
            sum2 = tmp2;
        }
        return sum1 + sum2;
        
    }
};