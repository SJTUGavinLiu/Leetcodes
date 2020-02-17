class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> ajac(numCourses, vector<int>());
        unordered_set<int> remain;
        //unordered_set<int> del;
        
        for(int i = 0; i < numCourses; i++)
            remain.insert(i);
        

        for(auto& pre: prerequisites)
            ajac[pre[0]].push_back(pre[1]);

        while(!remain.empty())
        {
            int next = -1;
            for(auto& cand: remain)
            {
                bool flag = 1;
                for(auto& base: ajac[cand])
                {
                    if(remain.count(base))
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                {
                    next =cand;
                    break;
                }
            }
            if(next == -1)
                return false;
            remain.erase(next);

        }
        return true;

    }
};


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> ajac(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        queue<int> qu;
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
            for(int& succ: ajac[cur])
            {
                indegree[succ]--;
                if(indegree[succ] == 0)
                {
                    cnt++;
                    qu.push(succ);
                }
                if(cnt == numCourses)
                    return true;
            }
        }
        return cnt == numCourses;

    }
};
