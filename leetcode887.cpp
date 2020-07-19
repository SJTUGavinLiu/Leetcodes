class Solution {
public:
    int superEggDrop(int K, int N) {
        if (N == 1) return 1;
        vector<int> cur(N+1,0);
        vector<int> next(N+1,0);
        for(int i = 0; i <= N; i++)
            cur[i] = i;

        for(int i = 2; i <= K; i++)
        {
            int x = 1;
            next[1] = 1;
            for(int j = 2; j <= N; j++)
            {
                while(x < j && cur[j - x] > next[x])    x++;
                next[j] = min(cur[j - x], next[x]) + 1;
            }
            swap(cur, next);
        }
        return cur.back();
    }
};