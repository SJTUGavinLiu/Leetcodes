class Solution {
private:
    int height;
    int width;
    vector<vector<int>> dirs {{1,0},{-1,0},{0,1},{0,-1}};
public:

    bool isValid(int x, int y)
    {
        return x >= 0 && x < height && y >= 0 && y < width;
    }

    void backtrack(int x, int y, vector<vector<char>>& board)
    {
        board[x][y] = 'Y';  //leave a mark
        for(auto& dir: dirs)
        {
            int x_next = x + dir[0];
            int y_next = y + dir[1];
            if(!isValid(x_next,y_next) || board[x_next][y_next] == 'X' || board[x_next][y_next] == 'Y')
                continue;
            
            backtrack(x_next,y_next, board); 
        }
    }
    void findEdge(vector<vector<char>>& board)
    {
        for(int i = 0; i < height; i++)
        {
            if(board[i][0] == 'O')
                backtrack(i,0,board);
            if(board[i][width-1] == 'O')
                backtrack(i,width-1,board);
        }

        for(int j = 0; j < width; j++)
        {
            if(board[0][j] == 'O')
                backtrack(0,j,board);
            if(board[height-1][j] == 'O')
                backtrack(height-1,j,board);
        }
    }

    void fill(vector<vector<char>>& board)
    {
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())   return;
        height = board.size();
        width = board[0].size();
        findEdge(board);
        fill(board);
        return;
    }
};