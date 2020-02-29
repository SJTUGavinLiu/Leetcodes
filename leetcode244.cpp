class WordDistance {
private:
    unordered_map<string, vector<int>> dict;
public:
    WordDistance(vector<string>& words) {
        int i = 0;
        for(auto& word: words)
            dict[word].push_back(i++);
        
    }
    
    int shortest(string word1, string word2) {
        int dis = INT_MAX;
        for(auto& i: dict[word1])
        {
            for(auto& j: dict[word2])
            {
                dis = min(dis, abs(i - j));
            }
        }
        return dis;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */