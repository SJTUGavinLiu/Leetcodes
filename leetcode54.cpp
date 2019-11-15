class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        if(matrix.size() == 0)  return {};
        vector<int> res;
        int top = 0;
        int bottom = matrix.size() -1;
        int left = 0;
        int right = matrix[0].size() -1;


        while (top <= bottom && left <= right)
        {
            if(top == bottom)
            {
                for(int j = left; j <= right; j++)
                    res.push_back(matrix[top][j]);
                break;
            }
            else if(left == right)
            {
                for(int i = top; i <= bottom; i++)
                    res.push_back(matrix[i][left]);
                break;
            }
            for(int j = left; j <= right; j++)
                res.push_back(matrix[top][j]);
            for(int i = top + 1; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            for(int j = right - 1; j >= left+1; j--)
                res.push_back(matrix[bottom][j]);
            for(int i = bottom; i >= top+1; i--)
                res.push_back(matrix[i][left]);
            top++;
            bottom--;
            left++;
            right--;
        }

        return res;

    }
};