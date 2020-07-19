class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int sum = 0;
        int max_ = INT_MIN;
        map<int, int> dict;
        for(auto& num: arr)
        {
            max_ = max(max_, num);
            sum += num;
            if(!dict.count(num))
                dict[num] = 1;
            else
                dict[num]++;
        }

        if(sum  <= target)
            return max_;


        int cnt = 0;
        int cover = 0;
        auto next = dict.rbegin();
        next++;
        for(auto iter = dict.rbegin(); iter != dict.rend(); iter++)
        {
            cnt += iter->second;
            cover += iter->second * iter->first;
            int p = (cover - sum + target) / cnt;
            if(next !=dict.rend() && p < next->first)
            {
                next++;
                continue;
            }
            int res1 = sum - cover + cnt * p;
            int res2 = sum - cover + cnt * (p+1);
            int res3 = sum - cover + cnt * (p-1);
            res1 = abs(res1 - target);
            res2 = abs(res2 - target);
            res3 = abs(res3 - target);
            if(res1 <= res2 && res1 <= res3)
                return p;
            else if(res2 <= res1 && res2 <= res3)
                return p+1; 
            else if(res3 <= res1 && res3 <= res2)
                return p-1;
        }

        return 0;
        
    }
};