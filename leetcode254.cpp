class Solution {
private:
    vector<int> tmp;
    vector<vector<int>> res;
    void helper(int start, int n)
    {
        // cout << start << '\t' << n << endl;
        tmp.push_back(start);
        int i = start;
        int cur = n / start;
        while(i <= sqrt(n))
        {
            if(cur % i == 0)
            {
                helper(i, cur);
            }
            i++;
        }
        if(!tmp.empty() && cur >= tmp.back())
        {
            tmp.push_back(cur);
            res.push_back(tmp);
            tmp.pop_back();
        }
        tmp.pop_back();
    }
public:
    vector<vector<int>> getFactors(int n) {
        int i = 2;
        while(i <= sqrt(n))
        {
            if(n % i == 0)
                helper(i, n);
            i++;
        }
        return res;
    }
};