class Solution {
private:
    vector<int> num;
    vector<char> opt;
    vector<int> helper(vector<int>& num, vector<char>& opt, int l, int r)
    {
        //cout << l << '\t' << r << endl;
        if(l > r)   return {};
        if(l == r)  return {num[l]};
        vector<int> res = {};
        for(int i = l; i < r; i++)
        {
            vector<int> left = helper(num,opt,l,i);
            vector<int> right = helper(num,opt,i+1,r);

            for(auto& n: left)
            {
                for(auto& m: right)
                {
                    switch(opt[i])
                    {
                        case '+': res.push_back(n + m); break;
                        case '-': res.push_back(n - m); break;
                        case '*': res.push_back(n * m); break;
                    }
                }                
            }
        }
        return res;

    }
public:
    vector<int> diffWaysToCompute(string input) {
        int i = 0;
        while(i < input.size())
        {
            if(input[i] >= '0' && input[i] <= '9')
            {
                int res = 0;
                while(i < input.size() && input[i] >= '0' && input[i] <= '9')
                {
                    res *= 10;
                    res += (input[i] - '0');
                    i++;
                }
                num.push_back(res);
            }
            else
            {
                opt.push_back(input[i]);
                i++;
            }
        }
        return helper(num, opt, 0, num.size() - 1);       
    }
};

