
class TrieNode {
private:
    TrieNode* next[26]{NULL};
    bool isEnd = false;
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
};



class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for(char c: word)
        {
            cur = cur->insert(c);
            
        }
        cur->set_end();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for(char c: word)
        {
            cur = cur->get(c);
            if(!cur)    return false;
        }
        return cur->is_end();
    }
    
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char c: prefix)
        {
            cur = cur->get(c);
            if(!cur)    return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */