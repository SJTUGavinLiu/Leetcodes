class Solution {
    int height;
    int width;
    int res;
public:
    bool isValid(int i, int j)
    {
        return i >= 0 && i < height && j >= 0 && j < width;
    }
    void Search(vector<vector<char>>& grid, int i, int j)
    {
        grid[i][j] = '2';
        if(isValid(i-1,j) && grid[i-1][j] == '1')   Search(grid, i-1, j);
        if(isValid(i+1,j) && grid[i+1][j] == '1')   Search(grid, i+1, j);
        if(isValid(i,j-1) && grid[i][j-1] == '1')   Search(grid, i, j-1);
        if(isValid(i,j+1) && grid[i][j+1] == '1')   Search(grid, i, j+1);
        
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        height = grid.size();
        width = grid[0].size(); 
        res = 0;
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                if(grid[i][j] == '1')
                {
                    Search(grid, i, j);
                    res++;
                }
            }
        }
        return res;

    }
};




/*
    并查集
*/

class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;
    int count;
    UnionFind(vector<vector<int>>& grid)
    {
        count = 0;
        int height = grid.size();
        int width = grid[0].size();
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                if(grid[i][j] == '1')
                {
                    parent.push_back(i*width+j);
                    count++;
                }
                else    
                    parent.push_back(-1);
                rank.push_back(0);
            }
        }

    }
public:

    int Find(int x)
    {
        return parent[x] == x ? x : (parent[x] = Find(parent[x]));
    }
    void Union(int x, int y)
    {
        int rootx = Find(x);
        int rooty = Find(y);
        if(rootx == rooty)  return;
        if(rank[rootx] > rank[rooty])
        {
            parent[rooty] = rootx;
        }
        else if(rank[rootx] < rank[rooty])
        {
            parent[rootx] = rooty;
        }
        else
        {
            parent[rooty] = rootx;
            rank[rootx]++;
        }
        count--;
    }

};

class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;
    int count;

public:
    int getCount()
    {
        return count;
    }
    UnionFind(vector<vector<char>>& grid)
    {
        count = 0;
        int height = grid.size();
        int width = grid[0].size();
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                if(grid[i][j] == '1')
                {
                    parent.push_back(i*width+j);
                    count++;
                }
                else    
                    parent.push_back(-1);
                rank.push_back(0);
            }
        }

    }
    int Find(int x)
    {
        return parent[x] == x ? x : (parent[x] = Find(parent[x]));
    }
    void Union(int x, int y)
    {
        int rootx = Find(x);
        int rooty = Find(y);
        if(rootx == rooty)  return;
        if(rank[rootx] > rank[rooty])
        {
            parent[rooty] = rootx;
        }
        else if(rank[rootx] < rank[rooty])
        {
            parent[rootx] = rooty;
        }
        else
        {
            parent[rooty] = rootx;
            rank[rootx]++;
        }
        count--;
    }

};


class Solution {
private:
    int height;
    int width;
    bool isValid(int i, int j)
    {
        return i >= 0 && i < height && j >= 0 && j < width;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        UnionFind uf(grid);
        height = grid.size();
        width = grid[0].size();
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {   
                if(grid[i][j] != '1')   continue;
                if(isValid(i-1,j) && grid[i-1][j] == '1')   uf.Union(i*width+j,(i-1)*width+j);
                if(isValid(i+1,j) && grid[i+1][j] == '1')   uf.Union(i*width+j,(i+1)*width+j);
                if(isValid(i,j-1) && grid[i][j-1] == '1')   uf.Union(i*width+j,i*width+j-1);
                if(isValid(i,j+1) && grid[i][j+1] == '1')   uf.Union(i*width+j,i*width+j+1);
            }
        }
        return uf.getCount();
    }

};