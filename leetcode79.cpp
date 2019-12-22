class Solution {
private:
    string s;
    int row;
    int col;
    vector<vector<int>> dirs;
public:
    bool isValid(int x, int y)
    {
        return 0 <= x and x < row && 0 <= y and y < col;
    }
    bool backtrack(int x, int y, int pos, vector<vector<char>>& board)
    {
        if(pos == s.size())
            return true;
        int x_next;
        int y_next;
        for(vector<int> &dir: dirs)
        {
            //cout<< dir[0] << " " << dir[1] <<endl;
            x_next = x + dir[0];
            y_next = y + dir[1];
            //cout<< x_next << " " << y_next <<endl;
            if(!isValid(x_next, y_next) || board[x_next][y_next] < 'A')
                continue;
            //cout << board[x_next][y_next] << " " << x_next << " " << y_next << endl;
            if(board[x_next][y_next] == s[pos])
            {
                board[x_next][y_next] -= 58;
                if(backtrack(x_next, y_next, pos+1, board))
                    return true;
                board[x_next][y_next] += 58;

            }
                
        }
        return false;
            
    }
    bool exist(vector<vector<char>>& board, string word) {
       
        if(board.empty() || board[0].empty() || word.empty())
            return false;
        dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        row = board.size();
        col = board[0].size();
        s = word;

        for(int x = 0; x < row; x++)
        {
            for(int y = 0; y < col; y++)
            {
                
                if(board[x][y] == s[0])
                {
                    board[x][y] -= 58;
                    if(backtrack(x,y,1,board))
                        return true;
                    board[x][y] += 58;
                } 
                    
            }
        }
        return false;
    }
};