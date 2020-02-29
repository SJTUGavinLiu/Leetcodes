class Solution {
private:
    string low;
    string high;
    unordered_map<char, char> dict {{{'6','9'}, {'9', '6'}, {'0', '0'}, {'1', '1'}, {'8', '8'}}, 5};
    vector<char> chs {{'9', '6', '8', '1', '0'}};
    int res = 0;
    void helper(string s)
    {
        if(low.size() < s.size() && s.size() < high.size())
        {
            if(s[0] != '0')
                res++;
        }
        else if(s.size() == low.size())
        {
            if(isValid(s))
                res++;
        }
        else if(s.size() == high.size())
        {
            if(isValid(s))
                res++;
            return;
        }
        else if(s.size() > high.size())
            return;
        for(auto& c:  chs)
            helper(c + s + dict[c]);

    }
    bool compare(string& a, string& b)
    {
        if(a.size() != b.size())    return a.size() >= b.size();
        return a >= b;
    }
    bool isValid(string& num)
    {
        return ((!num.empty() && num[0] != '0') || num == "0") && compare(num, low) && compare(high, num);
    }
public:
    int strobogrammaticInRange(string low_, string high_) {
        
        high = high_;
        low = low_;
        
        res = 0;

        helper("0");
        helper("1");
        helper("8");
        helper("");
        return res;
        
        
    }

};