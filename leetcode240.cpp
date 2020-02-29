class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int height = matrix.size();
        int width = matrix[0].size();

        int i = height - 1;
        int j = 0;

        while(i >= 0 && j < width)
        {
            if(matrix[i][j] == target)  return true;
            else if(matrix[i][j] < target)  j++;
            else    i--;
        }
        return false;

    }
};






class Solution {
    int target;
public:
    bool helper(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2)
    {
        //cout << x1 << '\t' << y1 << '\t' << x2 << '\t' << y2 << endl;
        if(x1 > x2 || y1 > y2)  return false;
        if(target < matrix[x1][y1] || target > matrix[x2][y2])  return false;

        int mid = (y1 + y2) / 2;
        int row = x1;
        while(row <= x2 && target >= matrix[row][mid])
        {
            if(matrix[row][mid] == targeat)
                return true;
            row++;
        }

        return helper(matrix, row, y1, x2, mid-1) || helper(matrix, x1, mid+1, row-1,y2);
        


    }
    bool searchMatrix(vector<vector<int>>& matrix, int tar) {
        if(matrix.empty() || matrix[0].empty()) return false;
        target = tar;
        return helper(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1);
    }
};



class Solution {
private:
    int height;
    int width;
    int target;
public:
    bool helper(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2)
    {
        //cout << x1 << '\t' << y1 << '\t' << x2 << '\t' << y2 << endl;
        if(x1 > x2 || y1 > y2)  return false;
        if(x1 == x2 && y1 == y2)
        {
            if(matrix[x1][y1] == target)
                return true;
            return false;
        }
        int midx = (x1 + x2) / 2;
        int midy = (y1 + y2) / 2;
        //cout << matrix[midx][midy] << endl;
        if(matrix[midx][midy] == target)    return true;
        else if(matrix[midx][midy] < target)
        {
            //cout << x2 << '\t' << midy << '\t' << matrix[x2][midy] <<endl;
            if(midx+1 <= x2 && midy+1 <= y2 && matrix[midx+1][midy+1] <= target && target <= matrix[x2][y2])
            {
                if(helper(matrix,midx+1,midy+1,x2,y2))
                    return true;
            }
            if(midy + 1 <= y2 && matrix[x1][midy+1] <= target && target <= matrix[midx][y2])
            {
                if(helper(matrix,x1,midy+1,midx,y2))
                    return true;
            }

            if(midx + 1 <= x2 && matrix[midx+1][y1] <= target && target <= matrix[x2][midy]) 
            {
                if(helper(matrix,midx+1,y1,x2,midy))
                    return true;
            }
            

        }
        else
        {
            if(helper(matrix, x1,y1,midx,midy))
                return true;
            if(midy + 1 <= y2 && matrix[x1][midy+1] <= target && target <= matrix[midx][y2])
            {
                if(helper(matrix,x1,midy+1,midx,y2))
                    return true;
            }
            if(midx+1 <= x2 && matrix[midx+1][y1] <= target && target <= matrix[x2][midy]) 
            {
                if(helper(matrix,midx+1,y1,x2,midy))
                    return true;
            }

        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int tar) {
        if(matrix.empty() || matrix[0].empty()) return false;
        height = matrix.size();
        width = matrix[0].size();
        target = tar;

        return helper(matrix,0,0,height-1,width-1);


    }
};