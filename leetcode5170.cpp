class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int cnt = n;
        vector<int> indegree(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            if(leftChild[i] != -1)
            {
                indegree[leftChild[i]]++;
                cnt--;
                if(indegree[leftChild[i]] >= 2)
                    return false;
            }   
            if(rightChild[i] != -1)
            {
                indegree[rightChild[i]]++;
                cnt--;
                if(indegree[rightChild[i]] >= 2)
                    return false;
            }  

        }
        //cout << cnt;
        return cnt == 1;
    }
};