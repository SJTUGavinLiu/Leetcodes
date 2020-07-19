class Solution {
private:
    vector<int> color;
    bool dfs(vector<vector<int>>& graph, int node, int tag) {
        if(color[node] == tag) return true;
        if(color[node] == -tag) return false;
        color[node] = tag;
        for(auto& nb: graph[node])
            if(!dfs(graph, nb, -tag))  return false;
            //else cout << nb << '\t';
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        color.resize(N, 0);
        for(int i = 0; i < N; i++)
        {
            if(color[i] != 0)   continue;
            if(!dfs(graph, i, 1))  return false;
        }
        return true;

    }
};

