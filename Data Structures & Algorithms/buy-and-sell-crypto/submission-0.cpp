class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int buyprice =INT_MAX;
        for(int price:prices){
            if(buyprice > price){
                buyprice = price;
            }
            else{
                int profit = price - buyprice;
                maxprofit = max(maxprofit,profit);
            }
        }
        return maxprofit;
    }
};
