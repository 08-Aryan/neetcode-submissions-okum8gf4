class Solution {
    vector<vector<int>> dp;
public:
    int dfs(int amount,vector<int> &coins,int idx){
        if(amount==0){
            return 1;
        }
        if(idx==coins.size()){
            return 0;
        }
        if(dp[amount][idx]!= -1){
            return dp[amount][idx];
        }
        int take = 0,nottake=0;
        nottake = dfs(amount,coins,idx+1);
        if(amount >= coins[idx]){  
            take = dfs(amount-coins[idx],coins,idx);
        }
        return dp[amount][idx] = nottake+take;

    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        dp.resize(amount+1,vector<int>(coins.size(),-1));
        return dfs(amount,coins,0);
    }
};
