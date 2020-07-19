class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
        int res = 0;
        for(int i = 0; i < A.size(); i++)
            dp[i][B.size() - 1] = A[i] == B.back();
        for(int j = 0; j < B.size(); j++)
            dp[A.size() - 1][j] = B[j] == A.back();
        for(int i = A.size() - 1; i >= 0; i--)
        {
            for(int j = B.size() - 1;  j >= 0; j--)
            {
                if(i != (A.size() - 1) && j != (B.size() - 1))
                    dp[i][j] = A[i] == B[j] ? 1 + dp[i+1][j+1] : 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};