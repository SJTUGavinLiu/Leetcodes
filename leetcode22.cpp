#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("", n, 0, 0, res);
        return res;
    }
    void helper(string str, int n, int l, int r, vector<string> &res)
    {
        if(l > n || r > n || r > l) return;
        if(l == n && r == n)
        {
            res.push_back(str);
        }
        helper(str + "(", n, l + 1, r, res);
        helper(str + ")", n, l, r + 1, res);
        return;
    }
};