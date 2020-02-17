class Solution {
public:
    int trailingZeroes(int n) {
        int five = 0;
        while(n)
        {
            n /= 5;
            five += n;
        }
        return five;
    }
};