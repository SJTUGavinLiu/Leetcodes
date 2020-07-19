class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> array(K, 0);
        int cur = 0;
        int pre = 0;
        for(int i = 0; i < A.size(); i++)
        {
            cur = (pre + A[i]) % K;
            if(cur < 0) cur += K;
            array[cur]++;
            pre = cur;
        }
        int res = array[0] * (array[0] - 1) / 2 + array[0]; 
        for(int i = 1; i < K; i++)
        {
            if(array[i] >= 2)
                res += array[i] * (array[i] - 1) / 2; 
        }
        return res;

    }
};