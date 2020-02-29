class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int flag = -1;  // 0 word1; 1 word2
        int len = INT_MAX;
        int pos = INT_MIN;
        if(word1 != word2)
        {
            for(int i = 0; i < words.size(); i++)
            {
                if(words[i] == word1)
                {
                    if(flag == 1)
                    {
                        if(len > (i - pos))
                            len = i - pos;
                    }

                    pos = i;
                    flag = 0;
                    
                }
                else if(words[i] == word2)
                {
                    if(flag == 0)
                    {
                        if(len > (i - pos))
                            len = i - pos;
                    }

                    pos = i;
                    flag = 1;
                    
                }
            }
        }
        else
        {
            for(int i = 0; i < words.size(); i++)
            {
                if(words[i] == word1)
                {
                    if(flag == -1)
                    {
                        pos = i;
                        flag  = 0;
                        continue;
                    }
                    if(len > (i - pos))
                        len = i - pos;
                        pos = i;
                }
            }
        }

        return len;
    }
};