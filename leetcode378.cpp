class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //int n = sqrt(0.25 + 2 * k) - 0.5;
        //int len = k - n * (n+1);
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> p(m, 1);

        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> qu;
        for(int i = 0; i < matrix.size(); i++)
            qu.push({matrix[i][0], i});
        
        for(int i = 0; i < k-1; i++)
        {
            pair<int, int> cur = qu.top();
            qu.pop();
            if(p[cur.second] != n)
                qu.push({matrix[cur.second][p[cur.second]++], cur.second});
        }
        return qu.top().first;
    }
};