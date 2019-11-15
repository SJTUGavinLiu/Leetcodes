class Solution {
    vector<vector<int>> placement;
    int res;
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
            res++;
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
        placement[cnt][0] = x;
        placement[cnt][1] = y;
        cnt++; 
    }
    void removeQueen()
    {
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
    int totalNQueens(int n) {
        if(n == 1)  return 1;
        for(int i = 0; i < n; i++){        
            placement.push_back({-1,-1});
        }    
        res = 0;
        cnt = 0;
        N = n;
        x = 0;
        y = 0;
        backtrack();
        return res;
    }
};