class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())  return;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j] == 0)
                {
                    for(int k = 0; k < matrix.size(); k++)
                        if(matrix[k][j] != 0)   matrix[k][j] = -11;
                    for(int k = 0; k < matrix[0].size(); k++)
                        if(matrix[i][k] != 0)   matrix[i][k] = -11;
                }
            
        
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j] == -11)  matrix[i][j] = 0;
            
    }
};



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())  return;
        bool flag1 = 0;
        bool flag2 = 0;
        if(matrix[0][0] == 0)
        {
            flag1 = flag2 = 1;
        }
        else
        {
            for(int k = 1; k < matrix.size(); k++)
                if(matrix[k][0] == 0)  flag1 = 1;
            for(int k = 1; k < matrix[0].size(); k++)
                if(matrix[0][k] == 0)  flag2 = 1;
        }

        for(int i = 1; i < matrix.size(); i++)
            for(int j = 1; j < matrix[0].size(); j++)
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            
        
        for(int i = 1; i < matrix.size(); i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int j = 1; j < matrix[0].size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < matrix[0].size(); j++)
        {
            if(matrix[0][j] == 0)
            {
                for(int i = 1; i < matrix.size(); i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if(flag1)
            for(int k = 0; k < matrix.size(); k++)
                matrix[k][0] = 0;
        if(flag2)
            for(int k = 0; k < matrix[0].size(); k++)
                matrix[0][k] = 0;
        
            
        
    }
};