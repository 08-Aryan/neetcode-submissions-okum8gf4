class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i = n-1;i>=0;i--){
            // 0 non holding -> 1 holding
            int buy = dp[i+1][0] - prices[i];
            int skip = dp[i+1][1];
            dp[i][1] = max(buy,skip);
            skip = dp[i+1][0];
            int sell = dp[i+2][1] + prices[i];
            dp[i][0] = max(sell,skip);
        }
        return dp[0][1];
    }
};