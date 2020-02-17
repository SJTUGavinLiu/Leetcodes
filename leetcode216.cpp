class Solution {
    vector<vector<int>> res;
    vector<int> tmp;
public:
    bool helper(int beg, int remain, int num)
    {
        //cout << beg << '\t' << remain << '\t' << num << endl;
        if((19-num)*num < 2 * remain)   return true;
        if( (9-beg+1) < num) return false;

        if(num == 1)
        {
            if(remain < beg)
                return false;
            tmp.push_back(remain);
            res.push_back(tmp);
            tmp.pop_back();
            return true;
        }
        while(1)
        {
            tmp.push_back(beg);
            if(!helper(beg+1,remain-beg, num-1))
            {
                tmp.pop_back();
                break;
            }
            tmp.pop_back();
            beg++;
        }
        return true;
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k > 9 || n > 45) return {};

        helper(1, n, k);
        return res;
    }
};