class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Max = 0;
        int buy = INT_MIN;
        int sale = 0;

        for(auto price: prices)
        {
            if(-price > buy)
                buy = -price;
            if(buy + price > sale)
                sale = buy + price;
        }

        return sale;
    }
};