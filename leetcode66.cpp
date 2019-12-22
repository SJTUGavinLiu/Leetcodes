class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty())  return {1};
        int m = digits.size() - 1;
        int carry = 1;
        for(int i = m; i >= 0; i--)
        {
            if(carry)
            {
                digits[i] += carry;
                carry = 0;
                if(digits[i] == 10)
                {
                    digits[i] = 0;
                    carry = 1;
                }
                else
                    break;
            }
        }
        if(carry)
            digits.insert(digits.begin(),1);
        return digits;

    }
};