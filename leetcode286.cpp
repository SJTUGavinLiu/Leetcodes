class Solution {
private:
    int height;
    int width;
    bool isValid(int x, int y)
    {
        return x >= 0 && x < height && y >= 0 && y <width;
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<int> qu;
        if(rooms.empty() || rooms[0].empty())   return;
        height = rooms.size();
        width = rooms[0].size();
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width;j++)
            {
                if(rooms[i][j] == 0)
                    qu.push(i * width + j);
            }
        }


        int layer = 1;

        queue<int> qu_tmp;

        while(!qu.empty())
        {
            while(!qu.empty())
            {
                int x = qu.front() / width;
                int y = qu.front() % width;
                //cout<<x<<'\t'<<y<<endl;
                qu.pop();
                for(auto& dir: dirs)
                {
                    //cout<<x+dir[0]<<'\t'<<y+dir[1]<<'\t'<<isValid(x + dir[0], y + dir[1])<<endl;
                    if(isValid(x + dir[0], y + dir[1]) && rooms[x + dir[0]][y + dir[1]] == INT_MAX)
                    {

                        rooms[x + dir[0]][y + dir[1]] = layer;
                        qu_tmp.push((x + dir[0]) * width + y + dir[1]);
                    }
                }
            }
            layer++;
            swap(qu,qu_tmp);
        }   


    }
};