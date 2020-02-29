class Vector2D {
private:
    vector<int> cache;
    vector<int>::iterator iter;
public:
    Vector2D(vector<vector<int>>& v) {
        for(int i=0; i<v.size(); i++) {
            for(int j=0; j<v[i].size(); j++) {
                cache.push_back(v[i][j]);
            }
        }
        iter = cache.begin();
    }

    int next() {
        iter++;
        return *(iter-1);
    }

    bool hasNext() {
        return iter != cache.end();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */