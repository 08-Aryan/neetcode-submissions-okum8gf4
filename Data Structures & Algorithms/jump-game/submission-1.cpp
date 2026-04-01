class Solution {
public:
    int dfs(vector<int> &nums,int i,vector<int> &dp){
        if(i>=nums.size()-1){
            return 1;
        }
        if(dp[i] !=-1){
            return dp[i];
        }
        int x = nums[i];
        if(x==0){
            return dp[i]=0;
        }
        for(int j=1;j<=x;j++){
            if(dfs(nums,i+j,dp)){
                return dp[i] = 1;
            }
        }
        return dp[i]=0;

    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return dfs(nums,0,dp);
        
    }
};
