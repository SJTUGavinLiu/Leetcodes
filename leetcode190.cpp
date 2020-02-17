
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i++)
        {
            res <<= 1;
            res += n&1;
            n >>= 1;
        }
        return res;
    }
};


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        uint32_t mask = 1 << 31;
        for(int i = 31; i >= 0; i--)
        {
            int exp = 2*i-32+1;
            if(exp >= 0)
                res = res + ((mask & n) >> exp);
            else
                res = res + ((mask & n) << -exp);
            mask = mask >> 1;
        }
        return res;
    }
};