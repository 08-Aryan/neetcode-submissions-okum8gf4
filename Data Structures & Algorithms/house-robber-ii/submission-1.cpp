class Solution {
public:
    int dfs(vector<int> nums,bool flag,int ind,vector<vector<int>> &dp){
        if(ind >= nums.size() || (flag && ind == nums.size()-1) ){
            return 0;
        }
        if(dp[ind][flag]!=-1){
            return dp[ind][flag];
        }
        return dp[ind][flag]=max(dfs(nums,flag,ind+1,dp),nums[ind]+dfs(nums,flag || ind==0, ind+2,dp ));
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        return max(dfs(nums,true,0,dp),dfs(nums,false,1,dp));
    }
};
