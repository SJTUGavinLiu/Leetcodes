class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(): parent(26), rank(26)
    {
        for(int i = 0; i < 26; i++)
        {
            parent[i] = i;
            rank[i] = 1;
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

};




class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf;
        for(auto& equ: equations)
        {
            if(equ[1] == '=')
                uf.Union(equ[0] - 'a', equ[3] - 'a');
        }
        
        for(auto& equ: equations)
        {
            if(equ[1] == '!' && uf.Find(equ[0] - 'a') == uf.Find(equ[3] - 'a'))
                return false;
        }

        return true;
    }
};