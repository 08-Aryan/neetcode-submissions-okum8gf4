class Solution {
public:

    long dfs(vector<int> &coins,int amount,vector<int> &dp){
        if(amount==0){
            return 0;
        }
        if(dp[amount-1]!=-1){
            return dp[amount-1];
        }
        long num = INT_MAX;
        for(auto coin:coins){
            if(coin <= amount){
                long ans = dfs(coins,amount-coin,dp);
                if(ans!=INT_MAX){
                num = min(num,1+ans);
            }
        }
        }   
        dp[amount-1]=num;
        return num;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount,-1);
        int mincoins = dfs(coins,amount,dp);

        return mincoins == INT_MAX ? -1 : mincoins;
    }
};
