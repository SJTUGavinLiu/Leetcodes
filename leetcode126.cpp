
/* 
    Solution 1
    Use BFS to find the lowest depth and store each layer in vector
    Use Backtrack to find the path
*/

class Solution {
private:
    int wordLen;
    string end;
public:
    bool isAjac(string a, string b)
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

    void backtrack(string cur, vector<vector<string>> &res, vector<string> &tmp, unordered_map<string, vector<string>>& nextStep)
    {
        if(isAjac(cur,end))
        {
            tmp.push_back(end);
            res.push_back(tmp);
            tmp.pop_back();
        }
        else
        {
            for(auto word: nextStep[cur])
            {
                tmp.push_back(word);
                backtrack(word, res, tmp, nextStep);
                tmp.pop_back();
            }
        }

    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(!s.count(endWord))   return res;
        wordLen = beginWord.size();
        end = endWord;
        unordered_set<string> p{beginWord};
        unordered_set<string> q;
        unordered_map<string, vector<string>> nextStep; // To store words that can be reached from the given word.
        bool flag = 0;  // when the path has been found, flag = 1
        while(!p.empty() && !flag)
        {
            for(auto iter1 = p.begin(); iter1 != p.end(); iter1++)
            {
                for(auto iter2 = s.begin(); iter2 != s.end(); iter2++)
                {
                    if(isAjac(*iter1, *iter2))
                    {
                        if(*iter2 == endWord)
                            flag = 1;
                        nextStep[*iter1].push_back(*iter2);
                        q.insert(*iter2);
                    }
                }
            }
            for(auto iter = q.begin(); iter != q.end(); iter++)
            {
                s.erase(*iter);
            }

            swap(p,q);
            q.clear();
        }

        vector<string> tmp(1, beginWord);
        if(flag)
        {
            backtrack(beginWord, res, tmp, nextStep);
        }

        return res;
        
    }
};



/* 
    Solution 2
    BFS updated
    128ms
*/ 


class Solution {
private:
    int wordLen;
    string end;
public:
    bool isAjac(string a, string b)
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
            for(auto word: nextStep[cur])
            {
                tmp.push_back(word);
                backtrack(word, res, tmp, nextStep);
                tmp.pop_back();
            }
        }

    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(!s.count(endWord))   return res;
        wordLen = beginWord.size();
        end = endWord;
        unordered_set<string> p{beginWord};
        unordered_set<string> q;
        unordered_map<string, vector<string>> nextStep; // To store words that can be reached from the given word.
        bool flag = 0;  // when the path has been found, flag = 1
        while(!p.empty() && !flag)
        {
            for(auto iter = p.begin(); iter != p.end(); iter++)
            {
                string str = *iter;
                for(int i = 0; i < wordLen; i++)
                {
                    char c = str[i];
                    for(char j = 'a'; j <= 'z'; j++)
                    {
                        str[i] = j;
                        if(str == endWord)
                            flag = 1;
                        if(s.count(str))
                        {
                            nextStep[*iter].push_back(str);
                            q.insert(str);
                        }
                    }

                    str[i] = c;
                }
            }
            for(auto iter = q.begin(); iter != q.end(); iter++)
            {
                s.erase(*iter);
            }

            swap(p,q);
            q.clear();
        }

        
        if(flag)
        {
            vector<string> tmp(1, beginWord);
            backtrack(beginWord, res, tmp, nextStep);
        }

        return res;
        
    }
};

/*
    Solution 3
    Bidirectional BFS
*/



static const auto __ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();



class Solution {
private:
    int wordLen;
    string end;
public:
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

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(!s.count(endWord))   return res;
        wordLen = beginWord.size();
        end = endWord;
        unordered_set<string> p1{beginWord};
        unordered_set<string> p2{endWord};
        unordered_set<string> q;
        unordered_map<string, vector<string>> nextStep; // To store words that can be reached from the given word.
        bool flag = 0;  // when the path has been found, flag = 1
        bool back = 0;  // when the direction of BFS is backward, back = 1
        s.erase(endWord);

        while(!p1.empty() && !p2.empty() && !flag)
        {
            if(p1.size() > p2.size())
            {
                swap(p1,p2);
                back = !back;
            }

            for (const string& w : p1)
                s.erase(w);
            for (const string& w : p2)
                s.erase(w);
            
            for(auto iter = p1.begin(); iter != p1.end(); iter++)
            {
                string str = *iter;
                for(int i = 0; i < wordLen; i++)
                {
                    char c = str[i];
                    for(char j = 'a'; j <= 'z'; j++)
                    {
                        str[i] = j;
                        if(p2.count(str))
                        {
                            flag = 1;
                            if(back)
                                nextStep[str].push_back(*iter);
                            else
                                nextStep[*iter].push_back(str);
                        }
                        if(s.count(str))
                        {
                            if(back)
                                nextStep[str].push_back(*iter);
                            else
                                nextStep[*iter].push_back(str);
                            q.insert(str);
                        }
                    }

                    str[i] = c;
                }
            }

            swap(p1,q);
            q.clear();
        }

        
        if(flag)
        {
            vector<string> tmp(1, beginWord);
            backtrack(beginWord, res, tmp, nextStep);
        }

        return res;
        
    }
};