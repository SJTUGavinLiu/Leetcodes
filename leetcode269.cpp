class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.empty())   return {};
        if(words.size() == 1)   return words[0];
        int len = words.size();
        vector<vector<bool>> mat(26, vector<bool>(26, 0));
        vector<int> indegree(26, -1);


        /* ajacent matrix */ 
        for(int i = 0; i < len - 1; i++)
        {
            int j = 0;
            while(j < words[i].size() && j < words[i+1].size())
            {
                //cout << words[i][j] << '\t' << words[i+1][j] << endl;
                if(words[i][j] == words[i+1][j])
                {
                    if(indegree[words[i][j]-'a'] == -1)
                        indegree[words[i][j]-'a'] = 0;
                    j++;
                    continue;
                } 
                if(!mat[words[i][j]-'a'][words[i+1][j]-'a'])
                {
                    mat[words[i][j]-'a'][words[i+1][j]-'a'] = 1;
                    if(indegree[words[i][j]-'a'] == -1)
                        indegree[words[i][j]-'a'] = 0;
                    if(indegree[words[i+1][j]-'a'] == -1)
                        indegree[words[i+1][j]-'a'] = 1;
                    else 
                        indegree[words[i+1][j]-'a']++;
                }    
                j++;   
                break;
            }
            
            while(j < words[i].size() || j < words[i+1].size())
            {
                if(j < words[i].size() && indegree[words[i][j]-'a'] == -1)
                    indegree[words[i][j]-'a'] = 0;
                
                if(j < words[i+1].size() && indegree[words[i+1][j]-'a'] == -1)
                    indegree[words[i+1][j]-'a'] = 0;
                j++;
            }

        }


        queue<int> qu;
        int cnt = 0;
        for(int i = 0; i < 26; i++)
        {
            //cout << indegree[i] << '\t';
            if(indegree[i] >= 0)
            {
                cnt++;
                if(indegree[i] == 0)
                    qu.push(i);
            }
        }

        string s(cnt, '0');
        int idx = 0;

        while(!qu.empty())
        {
            int cur = qu.front();
            qu.pop();
            s[idx++] = cur + 'a';
            cnt--;
            for(int j = 0; j < 26; j++)
            {
                if(mat[cur][j])
                {
                    indegree[j]--;
                    if(indegree[j] == 0)
                        qu.push(j);
                }
            }
        }

        //cout << s << endl;
        return cnt == 0 ? s : "";

        
    }
};