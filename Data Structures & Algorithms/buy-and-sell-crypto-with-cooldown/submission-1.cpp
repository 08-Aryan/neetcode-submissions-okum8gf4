class Solution {
    
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int> (2,0));;
        for(int i=n-1;i>=0;i--){
            for(auto b=1;b>=0;b--){
                int cooldown = dp[i+1][b];
                if(b==1){
                    int buy = dp[i+1][0] - prices[i];
                    dp[i][b] = max(buy,cooldown);

                }
                else{
                    int sell = dp[i+2][1] + prices[i];
                    dp[i][b] = max(sell,cooldown);
               }
                
            }
        }
        return dp[0][1];
    }
};
