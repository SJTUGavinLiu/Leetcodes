#include<vector>
#include<string>
#include <cmath>
int abs(int x)
{
    return x;
}
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = (dividend > 0) ^ (divisor > 0);
        dividend = abs(dividend);
        divisor = abs(divisor);

        
    }
};