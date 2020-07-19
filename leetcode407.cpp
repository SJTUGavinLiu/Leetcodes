class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int height = heightMap.size();
        int width = heightMap[0].size();
        if(height <= 2 || width <= 2)   return 0;
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> qu;
        vector<vector<bool>> vis(height, vector<bool>(width, 0));
        for(int i = 0; i < height; i++)
        {
            vis[i][0] = true;
            qu.push({heightMap[i][0], i, 0});
            vis[i][width - 1] = true;
            qu.push({heightMap[i][width - 1], i, width - 1});
            
        }
        for(int j = 0; j < width; j++)
        {
            vis[0][j] = true;
            qu.push({heightMap[0][j], 0, j});
            vis[height-1][j] = true;
            qu.push({heightMap[height-1][j], height-1, j});
        }


        vector<int> dirs = {-1, 0, 1, 0, -1};
        int res = 0;
        while(!qu.empty())
        {
            vector<int> cur = qu.top();
            qu.pop();
            for(int i = 0; i < 4; i++)
            {
                int x_next = cur[1] + dirs[i];
                int y_next = cur[2] + dirs[i+1];
                if(x_next < 0 || x_next >= height || y_next < 0 || y_next >= width || vis[x_next][y_next]) continue;
                //if(heightMap[x_next][y_next] < cur[0])
                res += (heightMap[x_next][y_next] < cur[0] ? (cur[0] - heightMap[x_next][y_next]) : 0);
                qu.push({max(heightMap[x_next][y_next], cur[0]), x_next, y_next});
                vis[x_next][y_next] = true;
            }
            
        }
        return res;
    }
};


/*
class Solution {
private:
    int res;
    int height;
    int width;
    vector<pair<int, int>> dirs = {
        {0, -1}, {0, 1}, {1, 0}, {-1, 0}
    };
    bool isValid(int x, int y)
    {
        return x >= 0 && x < height && y >= 0 && y < width;
    }
    int realHeight(int h)
    {
        if(h < 0)
            return -h - 1;
        else
            return h;
    }
    void helper(vector<vector<int>>& heightMap, int x, int y)
    {
        queue<pair<int,int>> qu;
        qu.push({x,y});
        vector<int> all;
        bool edge = 0;
        int edgeHeight = heightMap[x][y];
        int x_next,y_next;
        while(!qu.empty())
        {
            pair<int, int> cur = qu.front();
            all.push_back(cur);
            qu.pop();
            edge = cur.first == 0 || cur.first == height - 1 || cur.second == 0 || cur.second == width - 1;
            int curHeight = heightMap[cur.first][cur.second];
            heightMap[cur.first][cur.second] = -curHeight-1;  //标记已访问

            for(auto& dir: dirs)
            {
                x_next = cur.first + dir.first;
                y_next = cur.second + dir.second;
                if(isValid(x_next, y_next))
                {
                    int nextHeight = realHeight(heightMap[x_next][y_next]);
                    
                    if(nextHeight < edgeHeight)
                        edgeHeight = nextHeight;
                    if(heightMap[x_next][y_next] < 0)  continue;
                    if(curHeight > nextHeight)
                        qu.push({x_next, y_next});
                }
            }
        }
        if(!edge)
            for(auto& grid: all)
            {
                int h = realHeight(heightMap[grid.first][grid.second])
                if(h < edgeHeight)
                    res += (edgeHeight - h);
            }

    }
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        height = heightMap.size();
        width = heightMap[0].size();
        res = 0;
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                if(heightMap[i][j] > 0)
                    helper(heightMap, i, j);
            }
        }
        return res;
        
    }
};
*/