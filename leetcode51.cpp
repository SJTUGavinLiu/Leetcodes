
#include<vector>
#include<string>
#include<iostream>
using namespace std;
/* 记录点 */

class Solution {
    vector<string> curState;
    vector<vector<int>> placement;
    vector<vector<string>> res;
    int N, cnt, x, y;
public:

    bool isValid(vector<int>& pos)
    {
        if(pos[0] == x || pos[1] == y || abs(pos[0] - x) == abs(pos[1] - y))    return false;
        return true;
    }
    bool getResult()
    {
        if(cnt == N)
        {
            res.push_back(curState);
            return true;
        }
        return false;
    }
    void backtrack()
    {   
        if(x >= 1 + cnt)   return;  //省略一些情况
        
        bool flag =true;
        for(int i = 0; i < cnt; i++)
        {
            if(!isValid(placement[i]))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            placeQueen();
            if(getResult()) ;
            else if(nextStep())
            {
                backtrack();
                previousStep();               
            }
            removeQueen();
        }
        
        if(nextStep())
        {
            backtrack();
            previousStep();
        }
    }
    void placeQueen()
    {
        curState[x][y] = 'Q';
        placement[cnt][0] = x;
        placement[cnt][1] = y;
        cnt++; 
    }
    void removeQueen()
    {
        curState[x][y] = '.';
        cnt--;
    }
    bool nextStep()
    {
        if(x == N-1 && y == N-1)    return false;
        if(y == N-1)
        {
            x++;
            y = 0;
        }
        else    y++;
        return true;
    }
    
    void previousStep()
    {
        if(y == 0)
        {
            x--;
            y = N-1;
        }
        else    y--;
        
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n == 1)  return {{"Q"}};
        string tmp;
        for(int i = 0; i < n; i++)
            tmp += '.';
        for(int i = 0; i < n; i++){
            curState.push_back(tmp);
            placement.push_back({-1,-1});
        }    
        cnt = 0;
        N = n;
        x = 0;
        y = 0;
        backtrack();
        return res;
    }
};

/* 记录行列 */
class Solution {
public:
    int find_pos1(int r,int c, int n)
    {
        return n-1 + r - c;
    }
    int find_pos2(int r, int c, int n)
    {
        return r + c;
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n==0)    return {};
        vector<vector<string>> res;
        vector<string> cur;
        string ori;
        for(int i =0 ;i<n;i++)
            ori+='.';
        for(int i =0; i<n;i++)
            cur.push_back(ori);
        
        vector<bool> row(n,0);
        vector<bool> col(n,0);
        vector<bool> diag1(2*n-1,0);
        vector<bool> diag2(2*n-1,0);
        findres(n,0,res,cur,row,col,diag1,diag2);
        return res;
    }

    void findres(int n, int c,vector<vector<string>> &res, vector<string> &cur, vector<bool> &row,vector<bool> &col,vector<bool> &diag1,vector<bool> &diag2)
    {
        if(c == n)
        {
            res.push_back(cur);
            return;
        }
        for(int r = 0; r<n; r++)
        {
            if(row[r] || col[c] || diag1[find_pos1(r,c,n)] || diag2[find_pos2(r,c,n)])
                continue;
            cur[r][c]='Q';
            row[r] = col[c] = diag1[find_pos1(r,c,n)] = diag2[find_pos2(r,c,n)] =true;
            findres(n,c+1,res,cur,row,col,diag1,diag2);
            row[r] = col[c] = diag1[find_pos1(r,c,n)] = diag2[find_pos2(r,c,n)] =false;
            cur[r][c]='.';
        }
        
       

    }
};