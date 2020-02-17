class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int firstbuy = INT_MIN;
        int firstsale = 0;
        int secondbuy = INT_MIN;
        int secondsale = 0;

        for(auto price: prices) 
        {
            if(-price > firstbuy)   firstbuy = -price;
            if((firstbuy+price) > firstsale)  firstsale = firstbuy+price;
            if((firstsale-price) > secondbuy)    secondbuy = firstsale - price;
            if((secondbuy+price) > secondsale)  secondsale = secondbuy + price;
        }
        return secondsale;

    }
};