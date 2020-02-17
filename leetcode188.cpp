class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        if(prices.empty() || k == 0)  return 0;
        if (k >= prices.size() / 2)
		{
			int max = 0;
			for(int i = 1; i < prices.size(); ++i) {
				if(prices[i] > prices[i-1])
					max += prices[i] - prices[i-1];
			}
			return max;
		}
        int len = min(k,int(prices.size()));
        vector<int> buy(len,INT_MIN);
        vector<int> sell(len, INT_MIN);
        for(auto& price: prices)
        {
            buy[0] = max(buy[0],-price);
            sell[0] = max(sell[0], buy[0] + price);
            for(int i = 1; i < len; i++)
            {
                buy[i] = max(buy[i], sell[i-1]-price);
                sell[i] = max(sell[i], buy[i]+price);
            }

        }
        return sell.back();
    }
};
