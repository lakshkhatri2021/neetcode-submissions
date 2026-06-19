class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int l = 0;
        
        for(int r = 1;r < prices.size() ;r++){
            
            int best = prices[r] - prices[l];
            profit= max(profit,best);
            if(prices[r] < prices[l]){
                l = r;
            }
        }
        return profit;
    }
};
