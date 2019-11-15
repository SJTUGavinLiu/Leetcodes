class Solution {
vector<vector<int>> s;
public:
    void rotateItem(int x, int y, int N)
    {
        s[0][0] = y;
        s[0][1] = N-1-x;
        s[1][0] = x;
        s[1][1] = y;
        s[2][0] = N-1-y;
        s[2][1] = x;
        s[3][0] = N-1-x;
        s[3][1] = N-1-y;
        //return {{y,N-1-x},{x,y},{N-1-y,x},{N-1-x,N-1-y}};
    }
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int x = N/2;
        int y = (N+1)/2;
        int x_1;
        int y_1;
        int x_2;
        int y_2;
        for(int i = 0; i < 4; i++)
            s.push_back({0,0});

        int tmp;
        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                rotateItem(i,j,N);
                swap(matrix[s[0][0]][s[0][1]],matrix[s[1][0]][s[1][1]]);
                swap(matrix[s[1][0]][s[1][1]],matrix[s[2][0]][s[2][1]]);
                swap(matrix[s[2][0]][s[2][1]],matrix[s[3][0]][s[3][1]]);
            }
        }
    }
};