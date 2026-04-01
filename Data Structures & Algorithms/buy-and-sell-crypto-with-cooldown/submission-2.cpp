class Solution {
    
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        
        int buy1 = 0, buy2 =0,sell1 =0;
        for(int i=n-1;i>=0;i--){
            
                int dp_buy = max(sell1-prices[i],buy1);
                int dp_sell = max(buy2+prices[i],sell1);
                buy2 = buy1;
                buy1 = dp_buy;
                sell1 = dp_sell;
            }
            

        return buy1;
    }
};
