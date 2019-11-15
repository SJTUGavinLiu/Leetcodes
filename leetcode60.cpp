class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n,0);
        factorial[0] = 1;
        for(int i = 1; i < n ; i++)
        {
            factorial[i] = i*factorial[i-1];
        }
        vector<char> digits = { '1','2','3','4','5','6','7','8','9'};
        int cur;
        for(int i = 0; i < n; i++)
        {
            cur = (k - 1) / factorial[n-1-i];
            k = k - cur * factorial[n-1-i];
            s[i]=digits[cur];
            digits.erase(digits.begin()+cur);
        }
    }
};