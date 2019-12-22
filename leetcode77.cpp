class Solution {
private:
    vector<int> tmp;
    vector<vector<int>> res;
    int N;
public:
    void backtrack(int step, int remain)
    {
        if(remain == 0)
        {
            res.push_back(tmp);
            return;
        }
        for(int i = step; i <= (N-remain); i++)
        {
            tmp.push_back(i+1);
            backtrack(i+1,remain-1);
            tmp.pop_back();
        } 
    }
    vector<vector<int>> combine(int n, int k) {
        if(n < k)   return {};
        N = n;
        backtrack(0,k);
        return res;
        
    }
};