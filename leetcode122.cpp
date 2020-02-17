class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)    return 0;
        int Min = prices[0];
        int Max = prices[0];
        int res = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] <= prices[i-1])   
            {
                res+=(prices[i-1]-Min);
                Min = prices[i];
            }
            else
                if(i == prices.size()-1)    res += (prices[i]-Min);
        }
        return res;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())  return 0;
        int base = prices[0];
        int cur;
        int res = 0;
        for(auto price: prices)
        {
            if((price - base) > cur)
            {
                cur = price - base;
            }
            else
            {
                res += cur;
                cur = 0;
                base = price;
            }
        }

        res += cur;
        return res;

    }
};