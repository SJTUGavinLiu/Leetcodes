class Solution {
private:
public:
    double new21Game(int N, int K, int W) {
        vector<float> dp(K+W, 0);
        for(int i = K; i < K+W; i++)
        {
            if(i <= N)  dp[i] = 1;
            else    break;
        }
        double sum = 0.0;
        for(int j = 1; j <= W; j++)
            sum += dp[K+j-1];
        
        for(int i =  K-1; i >= 0; i--)
        {
            dp[i] = sum / W;
            sum = sum + dp[i] - dp[i + W];            
        }
        return dp[0];

    }
};