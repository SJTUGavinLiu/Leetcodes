#include<vector>
using namespace std;
/*
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
         result(board,0,0); 
    }
    bool result(vector<vector<char>>& board,int row,int column)
    {
	    if(row==9)
	        return true;
	    if(column==9)
	        return result(board,row+1,0);
	    
        if(board[row][column]=='.')
        {
            for(char index='1';index<='9';index++)
            {
                if(isValidSudoku(board,row,column,index))
                {
                    board[row][column] = index;
                    if(result(board,row,column+1))
                        return true;
                    board[row][column] = '.';
                }
            }
        }
        else
            return (result(board,row,column+1));
        
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board,int i,int j,char val ) {    
        for( int h=0;h<9;h++)
        {
            if(board[i][h]==val) return false; // check row 
            if(board[h][j]==val) return false; // check column 
            if(board[i-i%3+h/3][j-j%3+h%3]==val)return false; // check cub
        }
        return true;
    }
};

*/
class Solution {
private:
    vector<vector<bool>> rows;
    vector<vector<bool>> cols;
    vector<vector<bool>> blocks;
    bool sudokuSolved;
    
public:
    Solution():rows(9,vector<bool>(9,false)),
    cols(9,vector<bool>(9,false)),
    blocks(9,vector<bool>(9,false)),
    sudokuSolved(false){};
    
    bool isValid(int x, int y, int num)
    {
        num--;
        return !rows[x][num] && !cols[y][num] && !blocks[blockId(x,y)][num];
    }
    int blockId(int x, int y)
    {
        return x / 3 + (y / 3) * 3;
    }
    void placeNum(int x, int y, int num, vector<vector<char>>& board)
    {
        num--;
        rows[x][num] = true;
        cols[y][num] = true;
        blocks[blockId(x,y)][num] = true;
        board[x][y] = char(num + '1');
    }
    void removeNum(int x, int y, int num, vector<vector<char>>& board)
    {
        num--;
        rows[x][num] = false;
        cols[y][num] = false;
        blocks[blockId(x,y)][num] = false;
        board[x][y] = '.';
    }
    void nextNum(int x, int y, vector<vector<char>>& board)
    {
        if(y < 8) backward(x,y+1,board);
        else
        {
            if(x < 8)   backward(x+1,0,board);
            else    sudokuSolved = true;

        }
        
    }
    void backward(int x, int y, vector<vector<char>>& board)
    {
        //if(x == 9)  return;
        if(board[x][y] != '.')  nextNum(x,y,board);
        else
        {
            for(int i = 1; i <= 9; i++)
            {
                if(!isValid(x,y,i)) continue;
                placeNum(x,y,i,board);
                nextNum(x,y,board);
                if(sudokuSolved) return;
                removeNum(x,y,i,board);
            }  
        }
    }
    void solveSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')  continue;
                placeNum(i,j,board[i][j]-'0',board);
            }
        }
        backward(0,0,board);

    }
};