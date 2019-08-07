#include<vector>
#include<string>
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = (dividend > 0) ^ (divisor > 0);
        dividend = abs(dividend);
        divisor = abs(divisor);
    }
};