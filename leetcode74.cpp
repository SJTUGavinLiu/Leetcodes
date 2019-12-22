class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.empty() || matrix[0].empty())  return false;
        int beg_row = 0;
        int end_row = matrix.size() - 1;
        int mid;
        while(beg_row <= end_row)
        {
            mid = (beg_row + end_row) / 2;
            if(target <= matrix[mid].back() && target >= matrix[mid].front())
                break;
            else if(target >= matrix[mid].back())
            {
                beg_row = mid + 1;
            }
            else if(target <= matrix[mid].front())
            {
                end_row = mid - 1;
            }
        }

        if(beg_row > end_row)
            return false;
        else
        {
            int beg = 0;
            int end = matrix[mid].size() - 1;
            int tmp;
            while(beg <= end)
            {
                tmp = (beg + end) / 2;
                if(matrix[mid][tmp] == target)
                    return true;
                else if(matrix[mid][tmp] < target)
                {
                    beg = tmp + 1;
                }
                else
                {
                    end = tmp - 1;
                }
            }
        }
        return false;


    }
};