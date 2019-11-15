class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty())   return {newInterval};
        vector<vector<int>> res;
        int beg = intervals.size();
        
        for(int i = 0; i < intervals.size(); i++)
        {
            if(newInterval[0] < intervals[i][0]){
                beg = i;
                break;
            }
        }
        if(beg == 0)
        {
            int tmp = intervals.size();
            for(int i = 0; i < intervals.size(); i++)
            {
                if(intervals[i][0] <= newInterval[1] && newInterval[1] <= intervals[i][1])
                {
                    newInterval[1] = intervals[i][1];
                    tmp = i+1; 
                    break;
                }
                else if(intervals[i][0] > newInterval[1])
                {
                    tmp = i;
                    break;
                }
            }
            res.push_back(newInterval);
            for(int i = tmp; i < intervals.size(); i++)
            {
                res.push_back(intervals[i]);
            }
        }
        else if(beg == intervals.size())
        {
            
            for(int i = 0; i < beg - 1; i++)
            {
                res.push_back(intervals[i]);
            }
            if(intervals[beg-1][1] < newInterval[0])
            {
                res.push_back(intervals[beg-1]);
                res.push_back(newInterval);
            }
            else
            {
                newInterval[0] = intervals[beg-1][0];
                newInterval[1] = max(intervals[beg-1][1],newInterval[1]);
                res.push_back(newInterval);
            }
        }
        else
        {
            for(int i = 0; i < beg - 1; i++)
            {
                res.push_back(intervals[i]);
            }
            if(intervals[beg-1][1] >= newInterval[0])
            {
                int tmp = intervals.size();
                newInterval[0] = intervals[beg-1][0];
                newInterval[1] = max(intervals[beg-1][1],newInterval[1]);
                for(int i = beg; i < intervals.size(); i++)
                {
                    if(intervals[i][0] <= newInterval[1] && newInterval[1] <= intervals[i][1])
                    {
                        newInterval[1] = intervals[i][1];
                        tmp = i+1; 
                        break;
                    }
                    else if(intervals[i][0] > newInterval[1])
                    {
                        tmp = i;
                        break;
                    }
                }
                res.push_back(newInterval);
                for(int i = tmp; i < intervals.size(); i++)
                {      
                    res.push_back(intervals[i]);
                }
            }
            else
            {
                res.push_back(intervals[beg-1]);
                int tmp = intervals.size();
                for(int i = beg; i < intervals.size(); i++)
                {
                    if(intervals[i][0] <= newInterval[1] && newInterval[1] <= intervals[i][1])
                    {
                        newInterval[1] = intervals[i][1];
                        tmp = i+1; 
                        break;
                    }
                    else if(intervals[i][0] > newInterval[1])
                    {
                        tmp = i;
                        break;
                    }
                }
                res.push_back(newInterval);
                for(int i = tmp; i < intervals.size(); i++)
                {
                    res.push_back(intervals[i]);
                }
            }
        }
        
        return res;
        

    }
};
