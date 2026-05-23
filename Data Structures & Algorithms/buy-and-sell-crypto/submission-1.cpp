class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int bprice = prices[0];
        for(int price:prices){
            if(price > bprice){
                profit = max(profit,price-bprice);
            }
            else{
                bprice = price;
            }
        }
        return profit;
        
    }
};
