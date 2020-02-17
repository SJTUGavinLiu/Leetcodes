class TrieNode {
private:
    TrieNode* next[26]{NULL};
    bool isEnd = false;
    string word;
public:
    TrieNode(){}
    TrieNode* get(char c)
    {
        return next[c - 'a'];
    }
    TrieNode* insert(char c)
    {
        if(!next[c - 'a'])
            next[c - 'a'] = new TrieNode();
    
        return next[c - 'a'];
    }
    void set_end()
    {
        isEnd = true;
    }
    bool is_end()
    {
        return isEnd;
    }
    void set_word(string s)
    {
        word = s;
    }
    string get_word()
    {
        return word;
    }
};


class Solution {
private:
    vector<string> res;
    unordered_set<string> hash_set;
    int height,width;
    bool isValid(int i, int j)
    {
        return i >= 0 && i < height && j >= 0 && j < width;
    }
    void dfsSearch(TrieNode* cur, int i, int j, vector<vector<char>>& board, vector<vector<bool>>& mark)
    {
        
        
        cur = cur->get(board[i][j]);
        if(!cur)    return;
        
        if(cur->is_end())
        {
            string tmp = cur->get_word();
            if(!hash_set.count(tmp))
            {
                res.push_back(tmp);
                hash_set.insert(tmp);
            }
        }


        mark[i][j] = false;
        i -= 1;
        if(isValid(i,j) && mark[i][j]) dfsSearch(cur, i, j, board, mark);    
        i += 2;
        if(isValid(i,j) && mark[i][j]) dfsSearch(cur, i, j, board, mark);    
        i -= 1;
        j -= 1;
        if(isValid(i,j) && mark[i][j]) dfsSearch(cur, i, j, board, mark);    
        j += 2;
        if(isValid(i,j) && mark[i][j]) dfsSearch(cur, i, j, board, mark);    
        j -= 1;
        mark[i][j] = true;
    }   
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        height = board.size();
        width = board[0].size();
        vector<vector<bool>> mark(height, vector<bool>(width, 1));
        
        TrieNode* root = new TrieNode();
        for(auto& word: words)
        {
            TrieNode* cur = root;
            for(auto& c: word)
            {
                cur = cur->insert(c);
            }
            cur->set_end();
            cur->set_word(word);
        }


        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                dfsSearch(root, i, j, board, mark);
            }
        }
        return res;
    }
};

/*
    Version - store the index of string

*/

class TrieNode {
private:
    TrieNode* next[26]{NULL};
    bool isEnd = false;
    int word = -1;
public:
    TrieNode(){}
    TrieNode* get(char c)
    {
        return next[c - 'a'];
    }
    TrieNode* insert(char c)
    {
        if(!next[c - 'a'])
            next[c - 'a'] = new TrieNode();
    
        return next[c - 'a'];
    }
    void set_end()
    {
        isEnd = true;
    }
    bool is_end()
    {
        return isEnd;
    }
    void set_word(int s)
    {
        word = s;
    }
    int get_word()
    {
        return word;
    }
};


class Solution {
private:
    vector<string> res;
    int height,width;
    bool isValid(int i, int j)
    {
        return i >= 0 && i < height && j >= 0 && j < width;
    }
    void dfsSearch(TrieNode* cur, int i, int j, vector<vector<char>>& board, vector<vector<bool>>& mark, vector<string>& words, vector<bool>& found)
    {
        
        
        cur = cur->get(board[i][j]);
        if(!cur)    return;
        
        if(cur->is_end())
        {
            
            int idx = cur->get_word();
            //cout<< idx <<endl;
            if(!found[idx])
            {
                res.push_back(words[idx]);
                found[idx] = 1;
            }
        }


        mark[i][j] = false;
        i -= 1;
        if(isValid(i,j) && mark[i][j]) dfsSearch(cur, i, j, board, mark, words, found);    
        i += 2;
        if(isValid(i,j) && mark[i][j]) dfsSearch(cur, i, j, board, mark, words, found);    
        i -= 1;
        j -= 1;
        if(isValid(i,j) && mark[i][j]) dfsSearch(cur, i, j, board, mark, words, found);        
        j += 2;
        if(isValid(i,j) && mark[i][j]) dfsSearch(cur, i, j, board, mark, words, found);    
        j -= 1;
        mark[i][j] = true;
    }   
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        height = board.size();
        width = board[0].size();
        vector<vector<bool>> mark(height, vector<bool>(width, 1));
        vector<bool> found(words.size(), 0);
        TrieNode* root = new TrieNode();
        for(int i = 0; i < words.size(); i++)
        {
            TrieNode* cur = root;
            for(auto& c: words[i])
            {
                cur = cur->insert(c);
            }
            cur->set_end();
            cur->set_word(i);
        }


        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                dfsSearch(root, i, j, board, mark, words, found);    
            }
        }
        return res;
    }
};