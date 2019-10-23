#include<vector>
#include<unordered_set>
using namespace std;
using namespace std::tr1;

class Solution {
public:
    int blockId(int x, int y)
    {
        return x / 3 + (y / 3) * 3;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> blocks(9);
        int cur;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')  continue;
                cur = board[i][j] - '0';
                
                if(rows[i].find(cur) == rows[i].end())  rows[i].insert(cur);
                else return false;
                
                if(cols[j].find(cur) == cols[j].end())  cols[j].insert(cur);
                else return false;
                
                if(blocks[blockId(i,j)].find(cur) == blocks[blockId(i,j)].end())  blocks[blockId(i,j)].insert(cur);
                else return false;
            }
        }
        return true;

    }
};