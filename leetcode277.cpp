// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int i = 0;
        int j = 1;
        int pos = 2;
        while(pos <= n)
        {
            if(knows(i,j))
                i = pos++;
            else
                j = pos++;
        }
        i = i == n ? j : i;
        for(j = 0; j < n; j++)
        {
            if(j == i)  continue;
            if(knows(i, j) || !knows(j, i))
                return -1;
        }
        return i;
    }
};