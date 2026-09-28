class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int bp = prices[0];
        int max_profit = 0;

        for (int price : prices) {
            bp = min(bp, price);
            max_profit = max(max_profit, price - bp);
        }

        return max_profit;
    }
};