class Solution {
    vector<vector<int>> dp;
public:
    int dfs(vector<int> &prices , bool buying , int idx){
        if(idx >= prices.size()){
            return 0;
        }
        if(dp[idx][buying] != -1){
            return dp[idx][buying];
        }
        int cooldown = dfs(prices,buying,idx+1);
        // State of buying
        if(buying){
            int buy = dfs(prices,false,idx+1)-prices[idx];
            dp[idx][buying] = max(buy,cooldown);
        }
        // when could sell
        else{
            int sell = dfs(prices,true,idx+2) + prices[idx];
            dp[idx][buying] = max(sell,cooldown);
        }
        return dp[idx][buying];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n,vector<int> (2,-1));
        return dfs(prices,true,0);
    }
};
