bool comp(const string &a, const string &b)
{
    return a.size() > b.size();
}

class Suffix{
public:
    Suffix* layer[26];
    Suffix()
    {
        for(int i = 0; i <26; i++)
            layer[i] = NULL;
    }
};


class Solution {
private:
    Suffix* root;
public:
    int insert(string& word)
    {
        bool flag = 0;
        Suffix* node = root;
        for(int i = word.size() - 1; i >= 0; i--)
        {

            //cout << i;
            if(!node->layer[word[i] - 'a'])
            {
                flag = 1;
                node->layer[word[i] - 'a'] = new Suffix();
            }
            node = node->layer[word[i] - 'a'];
        }
        return flag ? (word.size() + 1): 0;
    }
    int minimumLengthEncoding(vector<string>& words) {
        if(words.empty())   return 0;
        root = new Suffix();
        int res = 0;
        sort(words.begin(), words.end(),comp);
        //cout << words[2];
        for(auto& word: words)
            res += insert(word);
        return res;
    }
};
