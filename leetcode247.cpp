class Solution {
    vector<string> res;
    unordered_map<char, char> dict {{{'6','9'}, {'9', '6'}, {'0', '0'}, {'1', '1'}, {'8', '8'}}, 5};
    vector<char> chs {{'9', '6', '8', '1'}};
    void helper(string s, int len)
    {
        if(len == 0)
        {
            res.push_back(s);
            return;
        }
        for(auto& c:  chs)
            helper(c + s + dict[c],len-1);
        if(len > 1)
            helper('0' + s + '0',len-1);
    }
public:
    vector<string> findStrobogrammatic(int n) {
        if(n % 2 == 1)
        {
            helper("0", n / 2);
            helper("1", n / 2);
            helper("8", n / 2);
        }
        else
        {
            helper("", n / 2);
        }

        return res;

    }
};