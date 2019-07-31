#include<vector>
using namespace std;
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int cur;
        while(x)
        {
            cur = x%10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && cur > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && cur < -8)) return 0;
            //important
            rev = rev*10 + cur;
        }
        return rev;
        
        
    }
};