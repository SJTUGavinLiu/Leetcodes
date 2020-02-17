class Solution {
private:
    // x < y
    int gcd(int x, int y)
    {
        return x == 0 ? y : gcd(y % x, x);
    }
    pair<int,int> getSlope(int x1, int y1, int x2, int y2)
    {
        int dx = x1 - x2;
        int dy = y1 - y2;
        if(dy == 0) return {y1, 0};
        if(dx == 0) return {0, x1};

        int d = gcd(dx, dy);
        return {dy / d, dx / d};
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 3)   return points.size();
        int len = points.size();
        //int same = 0;
        int res = 2;
        for(int i = 0; i < len; i++)
        {
            int same = 1;
            int max_count = 0;
            map<pair<int,int>, int> dict;
            for(int j = i+1; j < len; j++)
            {
                if(points[j][0] == points[i][0] && points[j][1] == points[i][1])
                {
                    same++;
                }
                else
                {
                    pair<int, int> slope = getSlope(points[i][0], points[i][1], points[j][0], points[j][1]);
                    if(!dict.count(slope))
                        dict[slope] = 1;
                    else
                        dict[slope]++;
                    max_count = max(max_count, dict[slope]);
                }
                
                
            }
            res = max(res, same + max_count);

        }
        return res;
    }
};