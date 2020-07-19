class Solution {
public:
    int height;
    int width;
    vector<vector<int>> pairs = {
        {}, {1, 3}, {2, 4}, {1, 4}, {3, 4}, {1, 2}, {2, 3}
    };
    vector<vector<int>> dirs = {
        {}, {0, -1}, {-1, 0}, {0, 1}, {1, 0}
    };
    bool isValid(int x, int y)
    {
        return x >= 0 && x < height && y >= 0 && y < width;
    }
    bool inPairs(int pre, int type_)
    {
        for(auto& item: pairs[type_])
            if(pre == item) return true;
        return false;
    }
    vector<int> pre2cur = {0, 3, 4, 1, 2};

    bool hasValidPath(vector<vector<int>>& grid) {
        height = grid.size();
        width = grid[0].size();
        if(height == 1 && width == 1)   return 1;
        for(auto& dir: pairs[grid[0][0]])
        {
            int x = dirs[dir][0];
            int y = dirs[dir][1];
            int pre = dir;
            if(isValid(x, y))
            {
                while(1)
                {

                    if(grid[x][y] == -1)    break;
                    int type_ = grid[x][y];
                    grid[x][y] = -1;
                    if(!inPairs(pre2cur[pre], type_))   break;
                    if(x == height - 1 && y == width - 1)   return 1;
                    int cur = pairs[type_][0] + pairs[type_][1] - pre2cur[pre];
                    x = x + dirs[cur][0];
                    y = y + dirs[cur][1];
                    if(!isValid(x, y))  break;
                    pre = cur;
                }
            }

        }
        return 0;
    }

};