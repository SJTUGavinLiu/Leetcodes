class TrieNode {
private:
    TrieNode* next[26] { NULL };
    bool isEnd = false;
public:
    TrieNode() {}
    TrieNode* get(char c) {
        return next[c-'a'];
    }
    TrieNode* insert(char c) {
        if(!next[c-'a'])
            next[c-'a'] = new TrieNode();
        return next[c-'a'];
    }
    void set_end()
    {
        isEnd = true;
    }
    bool show_end()
    {
        return isEnd;
    }
};






class WordDictionary {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c: word)
        {
            cur = cur->insert(c);
        }
        cur->set_end();
        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return simpleSearch(root, word, 0);
    }
    bool simpleSearch(TrieNode* cur, string& word, int pos)
    {
        if(pos == word.size())
            return cur->show_end();
        
        if(word[pos] == '.')
            return dfSearch(cur,word,pos);
        
    
        // trivial case;
        cur = cur->get(word[pos]);
        if(!cur)
            return false;
        return simpleSearch(cur, word, pos+1);
        
    }
    bool dfSearch(TrieNode* cur, string& word, int pos)
    {
        for(int i = 0; i < 26; i++)
        {
            //cout << i << '\t';
            if(cur->get(i+'a') && simpleSearch(cur->get(i+'a'), word, pos+1)) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */