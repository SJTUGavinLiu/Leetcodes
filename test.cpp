#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;


int main(){
    /*
    std::tr1::unordered_map<int,int> dict;
    dict[233] = 23333;
    dict[244] = 24444;
    std::cout<<dict[233]<<dict[244]<<std::endl;
    */

    queue<int> qu1;
    queue<int> qu2;

    qu1.push(1);
    qu1.push(2);
    qu1.push(3);
    qu1.push(4);
    qu2 = qu1;
    qu1.pop();
    cout << qu1.front() << qu2.front() << endl;
    return 0;
}


static const auto __ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();
// Author: Huahua
// Running time: 39 ms (better than 93.74%)
class Solution {
private:
    int wordLen;
    string end;
    bool isAjac(string& a, string& b)
    {
        // 0: not ajacent or same
        // 1: ajacent

        bool flag = 0;
        for(int i = 0; i < wordLen; i++)
        {
            if(flag && a[i] != b[i])    return 0;
            if(a[i] != b[i])    flag = 1;    
        }
        return flag;
    }

    void backtrack(string& cur, vector<vector<string>>& res, vector<string>& tmp, unordered_map<string, vector<string>>& nextStep)
    {
        if(isAjac(cur,end))
        {
            tmp.push_back(end);
            res.push_back(tmp);
            tmp.pop_back();
        }
        else
        {
            for(auto& word: nextStep[cur])
            {
                tmp.push_back(word);
                backtrack(word, res, tmp, nextStep);
                tmp.pop_back();
            }
        }

    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return ans;
        
        int l = beginWord.length();
        wordLen = l;
        end = endWord;
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        unordered_set<string> q;
        unordered_map<string, vector<string>> children;

        bool found = false;
        bool backward = false;
        dict.erase(endWord);
        while (!q1.empty() && !q2.empty() && !found) {            
            // Always expend the smaller queue first
            if (q1.size() > q2.size()) {
                std::swap(q1, q2);
                backward = !backward;
            }
            
            for (const string& w : q1)
                dict.erase(w);
            for (const string& w : q2)
                dict.erase(w);
                        
            
            
            for (const string& word : q1) {
                string curr = word;
                for (int i = 0; i < l; i++) {
                    char ch = curr[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        curr[i] = j;
                        
                        const string* parent = &word;
                        const string* child = &curr;
                        
                        if (backward)
                            std::swap(parent, child);
                        
                        if (q2.count(curr)) {
                            found = true;
                            children[*parent].push_back(*child);
                        } else if (dict.count(curr) && !found) {
                            q.insert(curr);
                            children[*parent].push_back(*child);
                        }
                    }
                    curr[i] = ch;
                }
            }
            
            std::swap(q, q1);
            q.clear();
        }
        
        if (found) {
            vector<string> path{beginWord};
            backtrack(beginWord, ans, path, children);
            //getPaths(beginWord, endWord, children, path, ans);
        }
        
        return ans;
    }

};