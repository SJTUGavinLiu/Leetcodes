class Solution {
public:
    static bool compare(vector<int>& x, vector<int>& y)
    {
        return x[0] < y[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty())   return {};
        vector<vector<int>> res;

        sort(intervals.begin(),intervals.end(),compare);
        int beg = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] > end)
            {
                res.push_back({beg,end});
                beg = intervals[i][0];
                end = intervals[i][1];
            }
            else
            {
                end = max(end, intervals[i][1]);
            }
        }
        res.push_back({beg,end});
        
        
        return res;
    }
};