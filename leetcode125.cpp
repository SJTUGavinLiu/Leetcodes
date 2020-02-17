class Solution {
public:
    char simplify(char c)
    {
        if(c <= 'Z' && c >= 'A')
        {
            return c - ('A' - 'a');
        }
        return c;
    }
    bool isValid(char c)
    {
        return (c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a') || (c <= '9' && c >='0');
    }
    bool isPalindrome(string s) {
        int beg = 0;
        int end = s.size() - 1;

        while(beg < s.size() && !isValid(s[beg]))
            beg++;
        if(beg == s.size()) return true;
        while(!isValid(s[end]))
            end--;
        while(beg < end)
        {
            if(simplify(s[beg]) != simplify(s[end]))
                return false;
            
            beg++;
            end--;
            
            while(!isValid(s[beg]))
                beg++;
            while(!isValid(s[end]))
                end--;
        }
        return true;

    }
};