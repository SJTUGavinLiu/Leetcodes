


class Solution {
private:
    int wordLen;
    string end;
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(!s.count(endWord))   return 0;
        if(beginWord == endWord)    return 1;
        wordLen = beginWord.size();
        end = endWord;
        unordered_set<string> p1{beginWord};
        unordered_set<string> p2{endWord};
        unordered_set<string> q;
        bool flag = 0;  // when the path has been found, flag = 1
        s.erase(endWord);
        int res = 1;

        while(!p1.empty() && !p2.empty() && !flag)
        {
            res += 1;
            if(p1.size() > p2.size())
            {
                swap(p1,p2);
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
                            return res;
                        if(s.count(str))
                            q.insert(str);
                    }

                    str[i] = c;
                }
            }

            swap(p1,q);
            q.clear();
        }

        

        return 0;
        
    }
};