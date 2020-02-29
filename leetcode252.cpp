bool cmp(vector<int>& a, vector<int>& b)
{
    return a[0] <= b[0];
}
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.empty())   return true;
        sort(intervals.begin(), intervals.end(), cmp);
        int pos = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++)
        {
            if(pos > intervals[i][0])   return false;
            pos = intervals[i][1];
        }
        return true;     
        
    }
};