class Solution {
public:
    vector<int> getRow(int numRows) {
        if(numRows == 0)  return {1};
        if(numRows == 1)  return {1,1};
        if(numRows == 2)  return {1,2,1};

        vector<int> tmp = {1,2,1};
        int pre,temp;

        for(int i = 3; i <= numRows; i++)
        {
            tmp.push_back(1);
            pre = tmp[0];
            for(int j = 1; j < i; j++)
            {
                temp = tmp[j];
                tmp[j] = pre + tmp[j];
                pre = temp;
            }
        }
        return tmp;
    }
};