
class DJ{
public:
    int id;
    int val;
    DJ(int id, int val): id(id), val(val){}
    bool operator > (const DJ& obj) const{ return val > obj.val; };
};





class Solution {
private:
    int height;
    int width;
    bool isValid(int x, int y)
    {
        return x >= 0 && x < height && y >= 0 && y < width;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        height = grid.size();
        width = grid[0].size();
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        int size_ = height * width;
        priority_queue<DJ,vector<DJ>,greater<DJ>> Q;
        bool* used = new bool[size_];
        int* d = new int[size_];
        for(int i = 0; i < size_; i++)
        {
            used[i] = 0;
            d[i] = INT_MAX;
        }
        Q.push((DJ){0, 0});
        d[0] = 0;
        int x,y,next,tmp;
        while(!Q.empty())
        {
            DJ cur = Q.top();
            Q.pop();
            if(used[cur.id])   continue;
            used[cur.id] = true;
            //cout << "cur: " << cur.id << '\t' << cur.val << endl;
            if(cur.id == size_ - 1)    
                break;
            y = cur.id % width;
            x = cur.id / width;
            

            for(int i = 0; i < 4; i++)
            {
                next = (x+dirs[i][0]) * width + y+dirs[i][1];
                //cout<<next<<endl;
                if(isValid(x+dirs[i][0],y+dirs[i][1]) && !used[next])
                {   
                    tmp = d[cur.id] + (grid[x][y] != i+1);
                    if(tmp < d[next])
                    {
                        d[next] = tmp;
                        Q.push((DJ){next, d[next]});   
                    }

                }
            }


        }

        return d[size_ - 1];


    }
};




/*
    BFS
*/


class Solution {
private:
    int height;
    int width;
    bool isValid(int x, int y)
    {
        return x >= 0 && x < height && y >= 0 && y < width;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        height = grid.size();
        width = grid[0].size();
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        int size_ = height * width;
        deque<int> Q;
        bool* used = new bool[size_];
        int* d = new int[size_];
        for(int i = 0; i < size_; i++)
        {
            used[i] = 0;
            d[i] = INT_MAX;
        }
        Q.push_front(0);
        d[0] = 0;
        int x,y,next,tmp;
        while(!Q.empty())
        {
            int cur = Q.front();
            Q.pop_front();
            if(used[cur])   continue;
            used[cur] = true;
            //cout << "cur: " << cur << '\t' << cur.val << endl;
            if(cur == size_ - 1)    
                break;
            y = cur % width;
            x = cur / width;
            

            for(int i = 0; i < 4; i++)
            {
                next = (x+dirs[i][0]) * width + y+dirs[i][1];
                //cout<<next<<endl;
                if(isValid(x+dirs[i][0],y+dirs[i][1]) && !used[next])
                {   
                    tmp = d[cur] + (grid[x][y] != i+1);
                    if(tmp < d[next])
                    {
                        d[next] = tmp;
                        if(grid[x][y] == i+1)
                            Q.push_front(next);
                        else
                            Q.push_back(next);
                    }

                }
            }


        }

        return d[size_ - 1];


    }
};