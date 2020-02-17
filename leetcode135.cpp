class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        int len = ratings.size();
        int sum = 0;
        
        vector<int> candies(len, 1);
        bool up = 0;    // Status: up
        //int pos = 0;    //postition of base
        //up = ratings[1] > ratings[0];
        for(int i = 0 ; i < len - 1; i++)
        {
            if(ratings[i] < ratings[i+1])
            {
                if(!up)
                {
                    // reset base
                    up = 1;
                    candies[i] = 1;
                }
                candies[i+1] = candies[i] + 1;

            }
            else if(ratings[i] == ratings[i+1])
            {
                if(up)  candies[i+1] = 1;
            }
            else
            {
                if(up)  up = 0;
            }

        }


        //up = ratings[len-1] < ratings[len-2];
        up = 0;
        for(int i = len -1; i >= 1; i--)
        {
            if(ratings[i] < ratings[i-1])
            {
                if(!up)
                {
                    candies[i] = 1;
                    up = 1;
                }
                if(candies[i-1] < candies[i] + 1)
                    candies[i-1] = candies[i] + 1;
            }
            else if(ratings[i-1] == ratings[i])
            {
                if(up && candies[i-1] < 1)
                    candies[i-1] = 1;
            }
            else
            {
                if(up)  up = 0;
            }
            sum += candies[i];
        }
        sum += candies[0];

        return sum;
    }
};

/* 
    逻辑精简
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        int len = ratings.size();
        int sum = 0;
        
        vector<int> candies(len, 1);
        for(int i = 0; i < len - 1; i++)
        {
            if(ratings[i] < ratings[i+1])
                candies[i+1] = candies[i] + 1;
        }
        for(int i = len - 1; i >= 1; i--)
        {
            if(ratings[i] < ratings[i-1])
                candies[i-1] = max(candies[i] + 1, candies[i-1]);
            sum += candies[i];
        }
        sum += candies[0];
        return sum;
    }

};


/* 
    常数空间
*/

class Solution {
public:
    int cal(int n )
    {
        return n*(n+1)/2;
    }
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        int len = ratings.size();
        int sum = 0;
        int cur = 0;
        int last = 0;
        int up = 0;
        int down = 0;
        for(int i = 0; i < len - 1; i++)
        {
            if(ratings[i+1] > ratings[i])   cur = 1;
            else if(ratings[i+1] < ratings[i])  cur = -1;
            else    cur = 0;

            if((last == -1 && cur >= 0) || (last == 1 && cur == 0))
            {
                sum = sum + cal(up) + cal(down) + max(up,down);
                up = 0;
                down = 0;
            }

            if(cur == 1)
                up++;
            else if(cur == -1)
                down++;
            else
                sum++;
            last = cur;
        }
        sum = sum + cal(up) + cal(down) + max(up,down) + 1; //补上最后一个点的基数
        return sum;
    }

};