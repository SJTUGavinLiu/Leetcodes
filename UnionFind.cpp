class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;
    UnionFind()
    {
        /* 根据具体题目补充 */
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
    }

};