class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 1;
        int profit = 0;
        while(i < prices.size()){
            if(prices[i] > prices[i-1]){
                profit += prices[i] - prices[i-1];
            }
            i++;
        }
        return profit;
    }
};