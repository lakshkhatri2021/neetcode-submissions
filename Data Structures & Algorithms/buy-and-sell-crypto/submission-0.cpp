class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int left = 0;
        int right = 1;

        while (right < prices.size()) {
            int best_rn = prices[right] - prices[left];
            profit = max(profit, best_rn);
            if(prices[left]> prices[right]){
                left = right;
            }
            right ++;
        }
        return profit;
    }
};
