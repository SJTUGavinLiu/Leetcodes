class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> ajac(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        queue<int> qu;
        vector<int> res;
        //unordered_set<int> remain;
        //unordered_set<int> del;

        int cnt = 0;
        for(auto& pre: prerequisites)
        {
            ajac[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }    

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                qu.push(i);
                cnt++;
            }
        }
        


        while(!qu.empty())
        {
            int cur = qu.front();
            qu.pop();
            res.push_back(cur);
            for(int& succ: ajac[cur])
            {
                indegree[succ]--;
                if(indegree[succ] == 0)
                {
                    cnt++;
                    qu.push(succ);
                }
                if(cnt == numCourses)
                    break;
            }
        }
        if(cnt == numCourses)
        {
            while(!qu.empty())
            {
                res.push_back(qu.front());
                qu.pop();
            }
            return res;
        }
        else
            return {};
    }
};


