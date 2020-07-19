
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> dict(26, vector<int>(27, 0));
        for(auto& vote: votes)
        {
            for(int i = 0; i < vote.size(); i++)
            {
                dict[vote[i] - 'A'][i]++;
                dict[vote[i] - 'A'].back() = 26 - (vote[i] - 'A');
            }
        }
        sort(dict.begin(), dict.end(), greater<vector<int>>());

        string res ="";
        for(int i = 0; i < 26; i++)
        {
            if(dict[i].back() != 0)
                res.push_back(26 - dict[i].back() + 'A');
        }
        return res;
    }
};




class Solution {
private:
    unordered_map<char, vector<int>> dict;
    int len;
    bool cmp(char& a, char& b)
    {
        for(int i = 0; i < len; i++)
        {
            if(dict[a][i] > dict[b][j]) return true;
            if(dict[a][i] < dict[b][j]) return false;
        }
        return a < b;
    }
public:
    string rankTeams(vector<string>& votes) {
        if(votes.empty())   return "";
        len = votes[0].size();
        string res(votes[0]);
        for(auto& c: votes[0])
            dict[c] = vector<int>(len, 0);

        for(string& vote: votes)
        {
            for(int i = 0; i < len; i++)
            {
                dict[vote[i]][i]++;
            }
        }

        sort(res.begin(), res.end(), cmp);

    }
};