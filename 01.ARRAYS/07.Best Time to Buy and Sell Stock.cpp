
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0];
        int profit = 0;
        int currentPrice = 0;
        for(int i = 1 ; i < prices.size() ; i++){
            currentPrice = prices[i];
            if(currentPrice < buyPrice){
                buyPrice = currentPrice;
            }

            profit = max(profit , currentPrice - buyPrice);
        }
        return profit;
    }
};