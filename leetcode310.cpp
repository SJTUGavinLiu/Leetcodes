/*
  O(n^2)
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      vector<int> lens(n, -1);
      vector<vector<int>> adjac(n);
      int minLen = INT_MAX;
      for(auto& edge: edges)
      {
        adjac[edge[0]].push_back(edge[1]);
        adjac[edge[1]].push_back(edge[0]);
      }
      
      for(int i = 0; i < n; i++)
      {
        int cnt = -1;
        queue<int> qu1, qu2;
        vector<bool> used(n, 0);
        qu1.push(i);
        while(!qu1.empty())
        {
          cnt++;
          while(!qu1.empty())
          {
            int node = qu1.front();
            qu1.pop();
            used[node] = true;
            for(auto& next: adjac[node])
            {
              if(used[next])  continue;
              qu2.push(next);
            }
          }
          swap(qu1,qu2);
        }
        lens[i] = cnt;
        minLen = min(minLen, cnt);
      }

      vector<int> res;
      for(int i = 0; i < n; i++)
      {
        if(lens[i] == minLen)
          res.push_back(i);
      }
      return res;
    }
};


/*
  O(n)
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      if(n == 1)    return {0};
      vector<int> degree(n, 0);
      for(auto& edge: edges)
      {
        degree[edge[0]]++;
        degree[edge[1]]++;
      }
      vector<vector<int>> adjac(n);
      for(auto& edge: edges)
      {
        adjac[edge[0]].push_back(edge[1]);
        adjac[edge[1]].push_back(edge[0]);
      }
      vector<int> qu1, qu2;
      for(int i = 0; i < n; i++)
        if(degree[i] == 1)  {
            qu1.push_back(i);
            degree[i] = -1;
        }
      
      int remain = n;
      int cnt = 0;
      while(!qu1.empty())
      {
        if(remain <= 2)
          return qu1;
        while(!qu1.empty())
        {
          int node = qu1.back();
          qu1.pop_back();
          remain--;
          for(auto& next: adjac[node])
          {
            degree[next]--;
            if(degree[next] == 1 || degree[next] == 0)
            {
                degree[next] = -1;
                qu2.push_back(next);
            }
          }
        }
        
        swap(qu1,qu2);
      }
      return {};

    }
};