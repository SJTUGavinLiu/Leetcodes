class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long num = numerator, den = denominator;
        string res = (num * den < 0) ? "-" : "";
        num = abs(num);
        den = abs(den);
        res += std::to_string(num / den);//1.整数部分
        num %= den;
        if (num != 0){
            res += ".";
        }//2.小数部分
        for (unordered_map<long long, int> m; num != 0; ) {
            if (m[num] != 0) {//出现循环节
                res.insert(m[num], "(");
                res.push_back(')');
                break;
            }
            m[num] = res.size();
            res += std::to_string(num * 10 / den);
            num = (num * 10) % den;
        }
        return res;
    }
};