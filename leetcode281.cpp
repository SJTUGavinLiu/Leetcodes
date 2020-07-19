class ZigzagIterator {
private:
    vector<vector<int>::iterator> iters;
    vector<vector<int>> v;
    int cnt = 0;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v = {v1, v2};
        iters.push_back(v[0].begin());
        iters.push_back(v[1].begin());
        //iter = iters.begin();
    }

    int next() {
        if(hasNext() && iters[cnt] != v[cnt].end())
        {
            int tmp = *iters[cnt];
            *iters[cnt]++;
            cnt = (cnt + 1) % 2;
            return tmp;
        }
        return -1;


    }

    bool hasNext() {
        for(int i = 0; i < 2; i++)
        {
            if(iters[cnt] != v[cnt].end())
                return true;
            cnt = (cnt + 1) % 2; 
        }
        return false;
    }
};