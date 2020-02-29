bool cmp(vector<int>& a, vector<int>& b)
{
    return a[0] <= b[0];
}
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int cnt = 0;
        priority_queue<int, vector<int>,greater<int>> heap;

        for(auto& inter: intervals)
        {
            if(heap.empty() || heap.top() > inter[0])
            {
                heap.push(inter[1]);
                cnt++;
            }
            else
            {
                int tmp = inter[1];
                heap.pop();
                heap.push(tmp);
            }

        }
        return cnt;
        
    }
};

