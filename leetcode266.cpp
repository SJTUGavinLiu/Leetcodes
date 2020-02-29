class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<bool>    isEven(256, 1);
        int cnt = 0;
        for(auto& c: s)
        {
            isEven[c] = !isEven[c];
            if(isEven[c])   cnt--;
            else cnt++;
        }

        return cnt <= 1;
    }
};