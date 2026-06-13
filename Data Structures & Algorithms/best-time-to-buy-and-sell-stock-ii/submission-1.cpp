class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int bprice = prices[0];
        for(int i = 1;i < prices.size();i++){
            if(prices[i] > bprice){
                profit += prices[i] - bprice;
            }
            bprice = prices[i];
        }
        return profit;
    }
};