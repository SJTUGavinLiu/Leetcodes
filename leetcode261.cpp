



class UnionFind{
private:
    int* parent;
    int* rank;
    int n;


public:
    UnionFind(int N)
    {
        n = N;
        parent = new int[N];
        rank = new int[N];
        //memset(rank, 0, sizeof(rank));
        for(int i = 0; i < N; i++)
        {
            parent[i] = i;
            rank[i] = 0;
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
    }

    bool isOne()
    {
        int cmp = parent[0];
        //cout << 0 << '\t' << parent[0] << endl;
        for(int i = 1; i < n; i++)
        {
            //cout << i << '\t' << parent[i] << endl;
            if(cmp != Find(i))
                return false;
        }
        return true;
    }

};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)    return false;
        if(edges.empty() && n == 1) return true;
        UnionFind uf(n);
        vector<bool> degree(edges.size(), 0);
        for(auto& edge: edges)
        {
            uf.Union(edge[0], edge[1]);
            if(!degree[edge[0]])
            {
                n--;
                degree[edge[0]] = 1;
            }
            if(!degree[edge[1]])
            {
                n--;
                degree[edge[1]] = 1;
            }
        }

        return n == 0 && uf.isOne();
    }
};
