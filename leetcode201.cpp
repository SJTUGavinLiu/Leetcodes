class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int len = 0;
        while(m<n)
        {
            len++;
            n /= 2;
            m /= 2;
            //cout << m << '\t' << n <<endl;
        }
        //cout << n << '\t' << len;
        return n << len;
    }
};