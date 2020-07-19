class Solution {
private:
    vector<vector<int>> graph;
    vector<int> color;
    bool dfs(int node, int tag) {
        if(color[node] == tag) return true;
        if(color[node] == -tag) return false;
        color[node] = tag;
        for(auto& nb: graph[node])
            if(!dfs(nb, -tag))  return false;
            //else cout << nb << '\t';
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        graph.resize(N+1);
        color.resize(N+1, 0);
        for(auto& link: dislikes)
        {
            graph[link[0]].push_back(link[1]);
            graph[link[1]].push_back(link[0]);
        }

        for(int i = 1; i <= N; i++)
        {
            if(color[i] != 0)   continue;
            if(!dfs(i, 1))  return false;
        }
        return true;
    }
};